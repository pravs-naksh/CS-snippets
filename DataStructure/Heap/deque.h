#ifndef _DEQUE_H_
#define _DEQUE_H_

#include "dlinklist.h"

typedef struct
{
  dlinklist *ll;
}deque;

deque* createDeque();
void dequePushFront(deque *q,leaf *d);
void dequePopFront(deque *q);
void dequePushBack(deque *q, leaf *d);
void dequePopBack(deque *q);
void dequeClean(deque *q);
leaf* dequeFront(deque *q);
leaf* dequeBack(deque *q);
#endif
