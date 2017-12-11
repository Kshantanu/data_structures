#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "common.h"

#define MAX_Q_SIZE 250

typedef struct queue
{
	int REAR;
	int FRONT;
	Leaf *node[MAX_Q_SIZE];
}queue;

/* frunction prototypes */


void createQueue(queue **Q);
void En_Queue(queue *Q, Leaf *node);
Leaf* De_Queue(queue *Q);
void destroy_queue(queue **Q);

#endif //__QUEUE_H__