#include "queue.h"


void createQueue(queue **Q)
{
	*Q = (queue*)malloc(sizeof(queue));
	if(*Q == NULL)
		return;
	
	(*Q)->FRONT = (*Q)->REAR = 0;
}


void En_Queue(queue *Q, Leaf *node)
{
	if(Q->REAR < MAX_Q_SIZE)
	{
		Q->node[Q->REAR++]	=	node;
	}
}

Leaf* De_Queue(queue *Q)
{
	Leaf *node = NULL;
	if(Q->FRONT != Q->REAR)
	{
		node = Q->node[Q->FRONT];
		Q->node[Q->FRONT] = NULL;
		Q->FRONT++;
	}

	return node;
}

void destroy_queue(queue **Q)
{
	free(*Q);
}