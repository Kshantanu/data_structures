#include <stdio.h>
#include <stdlib.h>


#include "queue.h"




Leaf* GetNode(int data)
{
	Leaf *temp = (Leaf*)malloc(sizeof(Leaf));
	if(!temp)
		return NULL;

	temp->data		=	data;
	temp->lChild	=	NULL;
	temp->rChild	=	NULL;

	return temp;
}

int CreateBinaryTree(Tree **tree, Tree_Type tType)
{
	if(tree == NULL)
		return FALSE;

	*tree	=	(Tree*)malloc(sizeof(Tree));
	if(!*tree)
		return FALSE;

	(*tree)->tType	=	tType;
	(*tree)->root	=	NULL;
	return TRUE;
}



void InsertNodeinSubtree(Leaf *node, int input)
{
	if(node->data <= input)
	{
		if(node->rChild == NULL)
		{
			Leaf *temp = GetNode(input);
			node->rChild = temp;
		}
		else
		{
			InsertNodeinSubtree(node->rChild,input);
		}
	}
	else
	{
		if(node->lChild == NULL)
		{
			Leaf *temp = GetNode(input);
			node->lChild = temp;
		}
		else
		{
			InsertNodeinSubtree(node->lChild,input);
		}
	}
}

void InsertNode(Tree *tree, int iData)
{
	if(tree->tType == BINARY_SEARCH_TREE)
	{
		if(tree->root == NULL)
		{
			Leaf *node = GetNode(iData);
			tree->root = node;
		}
		else
		{
			InsertNodeinSubtree(tree->root,iData);
		}
	}
}


void TraverseInOrder(Leaf *root)
{
	if(root->lChild != NULL)
		TraverseInOrder(root->lChild);
	printf("%d, ",root->data);
	if(root->rChild != NULL)
		TraverseInOrder(root->rChild);
}

void InOrderTraversal(Tree * tTree)
{
	TraverseInOrder(tTree->root);
}



void TraversePostOrder(Leaf *root)
{
	if(root->lChild != NULL)
		TraversePostOrder(root->lChild);
	if(root->rChild != NULL)
		TraversePostOrder(root->rChild);
	printf("%d, ",root->data);
}

void PostOrderTraversal(Tree * tTree)
{
	TraversePostOrder(tTree->root);
}



void TraversePreOrder(Leaf *root)
{
	printf("%d, ",root->data);
	if(root->lChild != NULL)
		TraversePreOrder(root->lChild);
	if(root->rChild != NULL)
		TraversePreOrder(root->rChild);
}

void PreOrderTraversal(Tree * tTree)
{
	TraversePreOrder(tTree->root);
}

void deleteNodes(Leaf *root)
{
	if(root->lChild != NULL)
		deleteNodes(root->lChild);

	if(root->rChild != NULL)
		deleteNodes(root->rChild);

	free(root);
	root = NULL;
}

void DeleteTree(Tree *tTree)
{
	deleteNodes(tTree->root);
	free(tTree);
	
}

void storeInorder(Leaf *root, int inorder[], int *index_ptr)
{
	if(root == NULL)
		return;

	storeInorder(root->lChild,inorder,index_ptr);

	inorder[*index_ptr]	=	root->data;
	(*index_ptr)++;


	storeInorder(root->rChild,inorder,index_ptr);
}

int countNodes(Leaf *root)
{
	if(root == NULL)
		return 0;

	return (countNodes(root->lChild) + countNodes(root->rChild) + 1);
}


void CreateBSTfromBinaryTree(Tree **tTree)
{
	int iCount = 0;
	int *nodeVal = NULL;
	int iIterator = 0;

	iCount	=	countNodes((*tTree)->root);
	nodeVal = (int*)calloc(iCount,sizeof(int));

	iCount	=	0;

	storeInorder((*tTree)->root,nodeVal,&iCount);

	DeleteTree(*tTree);
	*tTree = NULL;

	CreateBinaryTree(tTree,BINARY_SEARCH_TREE);

	while(iCount--)
	{
		InsertNode(*tTree,nodeVal[iIterator++]);
	}

	InOrderTraversal(*tTree);

}

int HeightOfTree(Leaf *root)
{
	int lHeight;
	int rHeight;

	if(root == NULL)
		return 0;
	else
	{
		lHeight = HeightOfTree(root->lChild);
		rHeight = HeightOfTree(root->rChild);

		if(lHeight > rHeight)
			return (lHeight+1);
		else
			return (rHeight+1);
	}
}

// Level Order Traversal : This method have runtime of O(n^2) : Starts //
int printLeafofLevel(Leaf* root, int i)
{
	if (root == NULL)
		return;
	if(i == 1)
		printf("%d ",root->data);
	else if (i > 1)
	{
		printLeafofLevel(root->lChild,i-1);
		printLeafofLevel(root->rChild,i-1);
	}
}

void LevelOrderTraversal(Leaf *root)
{
	int i =1;
	for(;i<=HeightOfTree(root);i++)
	{
		printLeafofLevel(root,i);
	}
}
// Level Order Traversal : This method have runtime of O(n^2) : Ends //


// Level Order Traversal : Runtime is :O(n) Starts

void PrintLevelOrder(Leaf* root)
{
	queue *Q = NULL;
    struct Leaf *temp_node = root;
	createQueue(&Q);


	while (temp_node)
    {
        printf("%d ", temp_node->data);
 
        /*Enqueue left child */
        if (temp_node->lChild)
			En_Queue(Q,temp_node->lChild);
            //enQueue(queue, &rear, temp_node->lChild);
 
        /*Enqueue right child */
        if (temp_node->rChild)
			En_Queue(Q,temp_node->rChild);
            //enQueue(queue, &rear, temp_node->rChild);
 
        /*Dequeue node and make it temp_node*/
		temp_node = De_Queue(Q);
    }

	destroy_queue(&Q);
}


// Level Order Traversal : Ends

void main()
{
	Tree *BinaryTree;
	CreateBinaryTree(&BinaryTree,BINARY_TREE);
	BinaryTree->root = GetNode(1);
	BinaryTree->root->lChild = GetNode(2);
    BinaryTree->root->rChild = GetNode(3);
    BinaryTree->root->lChild->lChild = GetNode(4);
    BinaryTree->root->lChild->rChild = GetNode(5);
	

	//LevelOrderTraversal(BinaryTree->root);
	PrintLevelOrder(BinaryTree->root);

	/*CreateBinarySearchTree(&BinaryTree);

	InsertNode(BinaryTree,100);

	InsertNode(BinaryTree,50);

	InsertNode(BinaryTree,150);
	InsertNode(BinaryTree,80);

	InsertNode(BinaryTree,30);
	InsertNode(BinaryTree,10);
	InsertNode(BinaryTree,20);
	InsertNode(BinaryTree,200);
	InsertNode(BinaryTree,120);
	InsertNode(BinaryTree,250);
	InsertNode(BinaryTree,170);


	printf("Inorder Traversal is: ");
	InOrderTraversal(BinaryTree);
	printf("\n\n");

	printf("Preorder Traversal is: ");
	PreOrderTraversal(BinaryTree);
	printf("\n\n");

	printf("Posrorder Traversal is: ");
	PostOrderTraversal(BinaryTree);

	DeleteTree(BinaryTree);*/
}