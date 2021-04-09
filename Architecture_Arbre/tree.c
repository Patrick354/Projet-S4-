#include <stdio.h>
#include <stdlib.h>
#include <err.h>


struct node
{
    char *label;
    struct node *left_child;
    struct node *right_child;
};

typedef struct node *t;


//Cette fonction nous permet de créer un noeud et de l'initialiser avec ses valeurs.
t creat(char *l ,t left_c, t right_c)
{
    t res;
    res = (t)malloc(sizeof(struct node));
    
    if(res == NULL)
    {
        err(1,"Error wihle allocating space");
        return NULL;
    }
    
    res->label = l;
    res->left_child = left_c;
    res->right_child = right_c;

    return res;
}


void add(t* pr,char *elt)
{
    if(pr == NULL)
    {
        err(1,"Wrong argument");
    }
    else if((*pr) == NULL)
    {
        *pr = creat(elt,NULL,NULL);
    }
    else if((*pr)->left_child == NULL)
    {
        (*pr)->left_child = creat(elt,NULL,NULL);
    }
    else if((*pr)->right_child == NULL)
    {
        (*pr)->right_child = creat(elt,NULL,NULL);
    }
    else
    {
        ajout((*pr)->left_child,elt);
    }
}
int main(void)
{
    t ls = NULL;
    t rs = NULL;

    rs = creat("a",ls,rs);
    ajout(rs,"Bonjour");

    return 0;



}






















