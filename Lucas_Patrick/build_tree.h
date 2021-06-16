#ifndef BUILD_TREE_h
#define BUILD_TREE_H

typedef struct node
{
	char value[50];
	struct node *left;
	struct node *right;
}node;


typedef struct node_number
{
	float data;
	struct node_number *left;
	struct node_number *right;
}node_number;

struct node_number *new_node(float data);

struct node *newNode(char  *value);

void printtabs(int numtabs);

void printtree_rec(node *root, int level);

void printtree_rec_number(node_number *root, int level);

void printtree(node* root);

float search_number(node_number *root, float* test);

void *build_tree_num(float *test);

char* search(node *root, char** test);

void *build_tree(char** test);

#endif
