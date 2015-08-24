#include "heap.h"

//allocate space for tree struct and set vars
heap* createHeap()
{
	heap *h = (heap*)malloc(sizeof(heap));
	h->root = NULL;
	h->q = createDeque();
	return h;
}

//malloc new leaf and set vars
leaf* createLeaf(data *d)
{

	leaf *l = (leaf*)malloc(sizeof(leaf));
	l->parent = NULL;
	l->right = NULL;
	l->left = NULL;
	l->d = d;
	return l;
}

//malloc data and set vars
data* createData(float valx,float valy)
{
	data* d = (data*)malloc(sizeof(data));
	d->valx = valx;
	d->valy = valy;
	return d;
}


//add a leaf to the tree.  heap must stay complete at all times.
void addLeaf(heap *h,data *d)
{
	//We already have code from binary trees that we can use to
	//fill the heap completely, this should closely mirror that code

	//If the heap is empty
	if(h->root == NULL)
	{
		//Create a new leaf to put in the heap
		leaf* new_leaf = createLeaf(d);
		//Set the root to be the new leaf.
		//Note that left, right and parent are all already appropriately set for the root node
		h->root = new_leaf;
		
		//This is definitely a heap, as it contains only one node.
		dequePushFront(h->q, new_leaf);
	} 
	//If the heap is not empty
	else 
	{
		//Then our node will get linked to the first node in the deque (previously this was a queue)
		leaf* parent = dequeFront(h->q);

		//If the parent does not have a left child, then this new node becomes the left child
		if(parent->left == NULL)
		{
			//Create a new leaf, and link it in appropriately
			leaf* new_leaf = createLeaf(d);
			new_leaf->parent = parent;
			parent->left = new_leaf;
			//Enqueue the leaf
			dequePushBack(h->q, new_leaf);

			//Now we may have violated the max-heap property, we can fix this by using percolate up
			percolateUp(new_leaf);
		}
		//Otherwise the parent node should only have space in the right child
		else 
		{
			//Just to be sure that the left child was non-null
			assert(parent->left != NULL && parent->right == NULL);
			//Create a new leaf, and link it in appropriately
			leaf* new_leaf = createLeaf(d);
			new_leaf->parent = parent;
			parent->right = new_leaf;
			//Enqueue the leaf
			dequePushBack(h->q, new_leaf);

			//Now the front of the deque does not have any more space, so remove it
			dequePopFront(h->q);

			//Now we may have violated the max-heap property, we can fix this by using percolate up
			percolateUp(new_leaf);
		}
	}

	return;
}

//percolate up
void percolateUp(leaf *current)
{
	//Check to see if we have any place left to percolate
	if(current->parent == NULL)
	{
		//There is no place else to go
		return;
	}
	else
	{
		data* parent_data = current->parent->d;
		data* current_data = current->d;

		//If this violates the max-heap property
//		if(parent_data->val < current_data->val)
		//if(parent_data->distance > current_data->distance) //min heap		
		if(parent_data->distance < current_data->distance)		//max heap
		{
			//Then we should switch the data
			current->parent->d = current_data;
			current->d = parent_data;

			//Since we swapped data, we need to make sure our changes are okay on the way up
			percolateUp(current->parent);
		}
		return;
	}
}

//percolate down
void percolateDown(leaf *current)
{
	//Check to see if we have an place left to percolate
	if(current->left == NULL && current->right == NULL)
	{
		//We are a leaf, so there's no place left to go
		return;
	}
	else if(current->left != NULL && current->right == NULL)
	{
		//We can only swap with our left child since no right child exists
		data* current_data = current->d;
		data* left_data = current->left->d;

		//If this violates the max-heap property
		//if(current_data->val < left_data->val)
		//if(current_data->distance > left_data->distance) //min heap
		if(current_data->distance < left_data->distance) //max heap
		{
			//Then we should switch the data
			current->d = left_data;
			current->left->d = current_data;

			//Since as this point we know that left is a leaf, we know that this is a heap
		}
		return;
	}
	else 
	{
		//We can swap with either child, since both children exist
		data* current_data = current->d;
		data* left_data = current->left->d;
		data* right_data = current->right->d;

		//If this violates the max-heap property, then take the maximum of the children and swap with current
//		if(current_data->val < left_data->val || current_data->val < right_data->val)
		//if(current_data->distance > left_data->distance || current_data->distance > right_data->distance)	//min heap	
		if(current_data->distance < left_data->distance || current_data->distance < right_data->distance) //max heap
		{
			//If we got this far, then the current node is not where it needs to be, and at least
			//one of the two children is bigger than the current

			//If the biggest child is the left child
//			if(left_data->val > right_data->val)
			//if(left_data->distance < right_data->distance) //min heap
			if(left_data->distance > right_data->distance)	//max heap
			{
				//Then current should switch data with the left child
				current->d = left_data;
				current->left->d = current_data;

				//Since we swapped data, we need to make sure our changes are okay on the way down
				percolateDown(current->left);
			}
			//Otherwise, the biggest child is the right child
			else
			{
				//Then current should switch data with the right child
				current->d = right_data;
				current->right->d = current_data;

				//Since we swapped data, we need to make sure our changes are okay on the way down
				percolateDown(current->right);
			}
			return;
		}
		//Otherwise everything is okay
		else
		{
			return;
		}
	}
}


//get the size of the tree
int treeSize(heap *h){
	return treeSize_r(h->root);
}

int treeSize_r(leaf *l){
	if(l != NULL)
		return (treeSize_r(l->left) + 1 + treeSize_r(l->right));
	else return 0;
}

//print data in in order
void inOrderPrint(heap *h){
	if(h == NULL) return;
	inOrderPrint_r(h->root);
}

void inOrderPrint_r(leaf *l){
	if(l==NULL) return;
	inOrderPrint_r(l->left);
	printf("%.2f %.2f %.2f \n",l->d->distance,l->d->valx,l->d->valy);
	inOrderPrint_r(l->right);
}


//print data in pre order
void preOrderPrint(heap *h){
	if(h == NULL) return;
	preOrderPrint_r(h->root);
}

void preOrderPrint_r(leaf *l){
	if(l==NULL) return;
	printf("%.2f %.2f %.2f \n",l->d->distance,l->d->valx,l->d->valy);
	preOrderPrint_r(l->left);
	preOrderPrint_r(l->right);
}

//print data in post order
void postOrderPrint(heap *h){
	if(h == NULL) return;
	postOrderPrint_r(h->root);
}

void postOrderPrint_r(leaf *l){
	if(l==NULL) return;
	postOrderPrint_r(l->left);
	postOrderPrint_r(l->right);
	printf("%.2f %.2f %.2f \n",l->d->distance,l->d->valx,l->d->valy);
}

//remove root. Tree must remain complete and can only be done through accessing the tree.
leaf* removeRoot(heap *h){
	//swap use exchange last node with root node
	//printf("checking back.... \n");
	if(h->root->left == NULL && h->root->right == NULL){
#if DEBUG
		printf("returning root\n");
#endif		
		return h->root;
	}
	leaf *lastNode = checkBack(h->q->ll);

#if DEBUG
	printf("root node: %f -- last node: %f \n",h->root->d->distance,lastNode->d->distance);
#endif
	swap(h->root,lastNode);
#if DEBUG	
	printf("swapped : root node: %f -- last node: %f \n",h->root->d->distance,lastNode->d->distance);
#endif	

	//update parent make it null
	
	if(lastNode->parent){
		if(lastNode->parent->right){
			lastNode->parent->right = NULL;
			dequePushFront(h->q, lastNode->parent);
			lastNode->parent = NULL;
		}
		else{
			lastNode->parent->left = NULL;
			lastNode->parent = NULL;
		}
		//call perc down with root leaf	
		percolateDown(h->root);
	}
	return lastNode;
}

void swap(leaf *l1,leaf *l2){
	float tempdistance,x,y;
	
	tempdistance = l1->d->distance;
	l1->d->distance = l2->d->distance;
	l2->d->distance = tempdistance;
	
	x = l1->d->valx;
	l1->d->valx = l2->d->valx;
	l2->d->valx = x;
	
	y = l1->d->valy;
	l1->d->valy = l2->d->valy;
	l2->d->valy = y;
}

void cleanHeap(heap *h){
	if(h->q)
		dequeClean(h->q);
	if(h->root)
		cleanHeap_r(h->root);
	free(h);
}

void cleanHeap_r(leaf *l){
	if(l == NULL) return;
	cleanHeap_r(l->left);
	cleanHeap_r(l->right);
	free(l->d);
	free(l);
}