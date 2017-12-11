#include <stdio.h>
#include <stdlib.h>



#define TRUE 1
#define FALSE 0

typedef enum Tree_Type
{
	BINARY_SEARCH_TREE,
	BINARY_TREE,
}Tree_Type;


typedef struct Leaf
{
	int data;
	struct Leaf *lChild;
	struct Leaf *rChild;
}Leaf;

typedef struct Tree
{
	Tree_Type	tType;
	Leaf *root;
}Tree;