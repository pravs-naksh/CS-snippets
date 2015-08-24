#ifndef _TREE_H_
#define _TREE_H_
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"


typedef struct 
{
  leaf *root;
  queue *q;
}tree;

//allocate space for tree struct and set vars
tree* createTree();
//malloc new leaf and set vars
leaf* createLeaf(data *d);
//malloc data and set vars
data* createData(float val);
//add a leaf to the tree.  leaf must stay complete at all times.
void addLeaf(tree *t,data *d);

//clean the tree
void cleanTree(tree *t);
void clean_tree(leaf *l);

//get the size of the tree
int treeSize(tree *t);
int treeSize_r(leaf *l);
//print data in in order
void inOrderPrint(tree *t);
void inOrderPrint_r(leaf *l);
//print data in pre order
void preOrderPrint(tree *t);
void preOrderPrint_r(leaf *l);
//print data in post order
void postOrderPrint(tree *t);
void postOrderPrint_r(leaf *l);
//remove root. Tree must remain complete and can only be done through accessing the tree. 
leaf* removeRoot(tree *t);
leaf* getParentleaf(leaf *l,leaf *delLeaf);

//check to see if tree is balenced.  if balanced return 1 and if not return -1.
int balancedTree(tree *t);

int isBalanced(leaf *l,int *height);

#endif
