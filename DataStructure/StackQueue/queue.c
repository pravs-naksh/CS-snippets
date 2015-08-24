#include "queue.h"

queue* createQueue(){
	queue* new_queue = (queue*)malloc(sizeof(queue)); 
	new_queue->ll = createlinklist();
  	return new_queue;
}

void queuePush(queue *q,data *d){
	addFront(q->ll,d);
}

data* queuePop(queue *q){
	return popBack(q->ll);
}

int queueSize(queue *q){
	return listSize(q->ll);
}

void queuePrint(queue *q){
	printList(q->ll);
}

void queueClean(queue *q){
	cleanList(q->ll);
}
