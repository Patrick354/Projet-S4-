#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "build_tree.h"

struct node_number *new_node(float data)
{
	struct node_number *result = malloc(sizeof(node_number));

	if(result != NULL)
	{
		result->left = NULL;
		result->right = NULL;
		result->data = data;
	}
	return result;
}




struct node *newNode(char  *value)
{
	struct node *result = malloc(sizeof(struct node));

	if(result != NULL)
	{
		result->left = NULL;
		result->right = NULL;
		strcpy(result->value,value);
	}

	return result;
}



void printtabs(int numtabs)
{
	for(int i = 0; i < numtabs; i++)
	{
		printf("\t");
	}
}

void printtree_rec(struct node *root, int level)
{
	if(root == NULL)
	{
		printtabs(level);
		printf("---<empty>--\n");
		return;
	}

	printtabs(level);
	printf("value = %s\n", root->value);
	printtabs(level);
	printf("left\n");

	printtree_rec(root->left,level+1);
	printtabs(level);

	printf("right\n");
	printtree_rec(root->right,level+1);
	printtabs(level);
	printf("done\n");

}


void printtree_rec_number(struct node_number *root, int level)
{
	if(root == NULL)
	{
		printtabs(level);
		printf("---<empty>--\n");
		return;
	}

	printtabs(level);
	printf("value = %f\n", root->data);
	printtabs(level);
	printf("left\n");

	printtree_rec_number(root->left,level+1);
	printtabs(level);

	printf("right\n");
	printtree_rec_number(root->right,level+1);
	printtabs(level);
	printf("done\n");

}




void printtree(struct node* root)
{
	printtree_rec(root,0);

}


float search_number(struct node_number *root, float* test)
{
	int i = 0;

	if(test[i] < root->data)
	{
		i+=1;
		if(test[i] >= root->right->data)
		{
			if(test[i] >= root->right->left->data)
			{
				if(test[i] >= root->right->left->left->data)
				{
					return root->right->left->left->left->right->data;

				}
				else
				{
					return root->right->left->left->right->data;
				}

			}
			else
			{
				return root->right->left->right->data;
			}
		
		}
		else
		{
			return root->right->right->data;
		}
	}
	else
	{
		return root->left->data;
	}
	




}




void *build_tree_num(float *test)
{
	struct node_number *root = new_node(0.61);

	struct node_number *n1 = new_node(0.23);

	struct node_number *n2 = new_node(0.49);

	struct node_number *n3 = new_node(0.51);

	struct node_number *n4 = new_node(0.73);

	struct node_number *n5 = new_node(0);

	struct node_number *n6 = new_node(1);

	
	root->left = n6;

	root->right = n1;

	n1->left = n2;

	n1->right = n5;

	n2->left = n3;

	n2->right = n6;

	n3->left = n4;

	n3->right = n5;

	n4->left = n6;

	n4->right = n6;

	printtree_rec_number(root,0);

	float res = search_number(root,test);


	printf("\n");

	printf("Expected Outcome is %f\n",res);




	free(root);
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);


}












char* search(struct node *root, char** test)
{
	int i = 0;

	if(strcmp(test[i],root->value)== 0)
	{
		i+=1;
		if(strcmp(test[i],root->left->value) == 0)
		{
			 return root->left->left->value;
		}
		else
		{
			return root->left->right->value;
		}
	}
	else
	{
		 return root->right->value;
	}
}





void *build_tree(char** test)
{

	struct node *root = newNode("Not Guessed");
	struct node *n1 = newNode("Missed");
	struct node *n2 = newNode("Correct");
	struct node *n3 = newNode("Not Correct");
	struct node *n4 = newNode("Not Correct");

	root->left = n1;
	n1->left = n2;
	n1->right = n3;
	root->right = n4;

	printtree(root);

	char *res = search(root,test);	

	printf("Expected outcome is %s\n",res);

	free(root);
	free(n1);
	free(n2);
	free(n3);
	free(n4);

}



/*
int* classify(char* row[0][3], Decision_node * tree)
{
    if(tree->Leaf == true)
    {
        return tree->c_c ;
    }    
s
    if(tree->question == 
}
*/

