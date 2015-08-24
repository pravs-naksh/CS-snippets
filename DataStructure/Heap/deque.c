#include "deque.h"

deque* createDeque()
{
	deque *q = (deque*)malloc(sizeof(deque));
	q->ll = createlinklist();
	return q;
}


void dequePushBack(deque *q,leaf *d)
{
	addBack(q->ll,d);
}

void dequePopBack(deque *q)
{
	popBack(q->ll);

}

void dequePushFront(deque *q, leaf *d)
{
	addFront(q->ll, d);	
}

void dequePopFront(deque *q)
{
	popFront(q->ll);
}

void dequeClean(deque *q)
{
	cleanList(q->ll);
	free(q);
}

leaf* dequeFront(deque *q)
{
	return checkFront(q->ll);
}

leaf* dequeBack(deque *q)
{
	return checkBack(q->ll);
}
