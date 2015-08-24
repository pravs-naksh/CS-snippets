#include "tree.h"

tree* createTree(){
  tree* t = (tree*)malloc(sizeof(tree));
  t->root = NULL;
  t->q = createQueue();
  return t;
}

leaf* createLeaf(data *d){
  leaf* l = (leaf*)malloc(sizeof(leaf));
  l->right = NULL;
  l->left = NULL;
  l->d = d;
  return l;
}

data* createData(float val)
{
  data* d = (data*)malloc(sizeof(data));
  d->val = val;
  return d;
}

void addLeaf(tree *t,data *d){
  if(t->root == NULL){
     leaf *l = createLeaf(d);
     t->root = l;
     queuePush(t->q,l);
  }
  else{
	leaf *l;
     l = queueFront(t->q);
     if(l->left == NULL){ /* insert at left */
		leaf *l1 = createLeaf(d);
		l->left = l1;
		queuePush(t->q,l1);
	} else if(l->right == NULL) { /* insert at right */
		leaf *l1 = createLeaf(d);
		l->right = l1;
		queuePush(t->q,l1);
		queuePop(t->q);
	}
  }
}

int treeSize(tree *t){
	return treeSize_r(t->root);
}

int treeSize_r(leaf *l){
	if(l!= NULL)
		return treeSize_r(l->left) + 1 + treeSize_r(l->right);
	else return 0;
}

//print data in in order
void inOrderPrint(tree *t){
	inOrderPrint_r(t->root);
}

void inOrderPrint_r(leaf *l){
	if(l == NULL) return;
	inOrderPrint_r(l->left);
	printf("%f\n",l->d->val);
	inOrderPrint_r(l->right);
}
//print data in pre order
void preOrderPrint(tree *t){
	preOrderPrint_r(t->root);
}

void preOrderPrint_r(leaf *l){
	if(l == NULL) return;
	printf("%f\n",l->d->val);
	preOrderPrint_r(l->left);
	preOrderPrint_r(l->right);
}
//print data in post order
void postOrderPrint(tree *t){
	postOrderPrint_r(t->root);
}

void postOrderPrint_r(leaf *l){
	if(l == NULL) return;
	postOrderPrint_r(l->left);
	postOrderPrint_r(l->right);
	printf("%f\n",l->d->val);
}

leaf* removeRoot(tree *t){
	leaf* toReturn = queueBack(t->q);
	if(toReturn == NULL) return NULL;
	float temp =  toReturn->d->val;
	toReturn->d->val = t->root->d->val;
	t->root->d->val = temp;
	leaf* parLeaf = getParentleaf(t->root,toReturn);
	printf("Parent is %f\n",parLeaf->d->val);	
	if(parLeaf->right != NULL) parLeaf->right = NULL;
	else if(parLeaf->left) parLeaf->left = NULL;
	return  toReturn;
}

leaf* getParentleaf(leaf *l,leaf *delLeaf){
	if(l != 0) {
		if(l->left){
			if (l->left->d->val == delLeaf->d->val)
				return l;
		}
		getParentleaf(l->left,delLeaf);
      		if(getParentleaf(l->left,delLeaf) == NULL){ 
			if(l->right){         
				if (l->right->d->val == delLeaf->d->val)
					return l;
			}
			getParentleaf(l->right,delLeaf);
		}
	} else
       		return NULL;
}

int balancedTree(tree *t){
	int height = 0;
	return isBalanced(t->root,&height);
}

int isBalanced(leaf *lf,int* height)
{
  int lh = 0, rh = 0;  
  int l = 0, r = 0;
     
  if(lf == NULL)
  {
    *height = 0;
     return 1;
  }
  l = isBalanced(lf->left, &lh);
  r = isBalanced(lf->right,&rh);
  *height = (lh > rh? lh: rh) + 1;

  if((lh - rh >= 2) || (rh - lh >= 2))
    return 0;
     
  else return l&&r;
}

void cleanTree(tree *t){
	queueClean(t->q);
	clean_tree(t->root);
	free(t);
}

void clean_tree(leaf *l){
        if(l==NULL) return;
        clean_tree(l->left);
        clean_tree(l->right);
        free(l->d);
        free(l);
}

