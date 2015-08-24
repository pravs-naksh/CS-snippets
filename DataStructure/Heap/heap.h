#ifndef _heap_H_
#define _heap_H_
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "deque.h"

//Note, a deque is a data structure similar to a queue. It stands for
//Double Ended Queue -- this means that instead of only adding to one
//end and removing from the other, we can add and remove from both ends
//Check out the code in deque.c for further understanding



#include "dlinklist.h"

typedef struct 
{
  leaf *root;
  deque *q;
}heap;

//allocate space for tree struct and set vars
heap* createHeap();

//malloc new leaf and set vars
leaf* createLeaf(data *d);

//malloc data and set vars
data* createData(float valx,float valy);

//add a leaf to the tree.  heap must stay complete at all times.
void addLeaf(heap *h,data *d);

//percolate up
void percolateUp(leaf *current);

//percolate down
void percolateDown(leaf *current);

//get the size of the tree
int treeSize(heap *h);
int treeSize_r(leaf *l);

//print data in in order
void inOrderPrint(heap *h);
void inOrderPrint_r(leaf *l);

//print data in pre order
void preOrderPrint(heap *h);
void preOrderPrint_r(leaf *l);

//print data in post order
void postOrderPrint(heap *h);
void postOrderPrint_r(leaf *l);

//remove root. Tree must remain complete and can only be done through accessing the tree.
leaf* removeRoot(heap *h);
/**
Note that since we're using a deque this becomes easier. To remove the root, we have to
take the last leaf. We know where the last leaf is, and we can find out whether or not
its parent is in the "free space deque" through the parent pointer. If when we move the
last leaf we have to add the last leaf's parent back into the deque, then the deque
allows us to do that, where a queue would not.
  **/

void swap(leaf *l1,leaf *l2);
void cleanHeap(heap *h);
void cleanHeap_r(leaf *l);

//check to see if tree is balanced.  if balanced return 1 and if not return -1.
int balancedTree(heap *h);
#endif
