#include "linklist.h"

//reserve space for a new linklist, set initial variables, and return linklist
linkList* createlinkList(){
	linkList *newlinkList = (linkList*)malloc(sizeof(linkList));
	newlinkList->head = NULL;
	newlinkList->tail = NULL;
	return newlinkList;
}

//reserve space for new node, set variables and return
node* createNode(data *d){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->d = d;
	return newnode;
}

//reserve space for a new data struct,set variables and return
data* createData(char *first, char *last, int age, int id){
	data *newData = (data*)malloc(sizeof(data));
	strcpy( newData->first, first ); //newData->first = first;
	strcpy( newData->last, last ); //newData->last = last;
	newData->age = age;
	newData->id = id;
	return newData;
}

//create a new node, set the data pointer, and add to front of linklist
void addFront(linkList *ll,data *d){
	node *newnode = createNode(d);
	if(ll->head == NULL && ll->tail == NULL)
	  {
	    ll->head = newnode;
	    ll->tail = newnode;
	  }
	else 
	  {
	    newnode->next = ll->head;
	    ll->head = newnode;
	  }
}

//create a new node, set the data pointer, and add to back of linklist
void addBack(linkList *ll,data *d){
	node *newnode = createNode(d);
	if(ll->head == NULL && ll->tail == NULL)
	  {
	    ll->head = newnode;
	    ll->tail = newnode;
	  }
	else 
	  {
	  	node *temp = ll->head;
	  	while(temp != ll->tail)
	  		temp=temp->next;
	  	
	  	ll->tail->next = newnode;
	  	ll->tail = newnode;
	  }
}

//print values in the data structures in the linklist
void printList(linkList *ll){
	node *temp = ll->head;
	
	while(temp != NULL){
		printf("%s\n%s\n%d\n%d\n",temp->d->first,temp->d->last,temp->d->age,temp->d->id);
		temp = temp->next;
	}
}

//count the number of elements in the linklist and return the count
int listSize(linkList *ll){
	node *temp = ll->head;
	int size = 0;
	while(temp != NULL){
		size++;
		temp = temp->next;
	}
	return size;
}

//remove node from the front of the list and return the data element
data* popFront(linkList *ll){
	if(ll->head == NULL && ll->tail == NULL)return NULL;
	if(ll->head == ll->tail)
	  {
	    node *deltemp= ll->head;
	    ll->head = NULL;
	    ll->tail = NULL;
	    return deltemp->d;
	  }
	else
	  {
	    node* deltemp = ll->head;
	    ll->head=ll->head->next;
	    return deltemp->d;
	  }
	
}

//remove node from the front of the list and return the data element
data* popBack(linkList *ll){
	if(ll->head == NULL && ll->tail == NULL)return NULL;
	if(ll->head == ll->tail)
	{
		node *deltemp =ll->head;
	  	ll->head = NULL;
	  	ll->tail = NULL;
	  	return deltemp->d;
	}
	else
	{
	  	node *lasttemp = ll->head;
	  	node *deltemp = ll->head->next;
	  	while(deltemp != ll->tail)
		{
	  		lasttemp = deltemp;
	  		deltemp=deltemp->next;
		}
		lasttemp->next = NULL;
	  	ll->tail = lasttemp;
	  	return deltemp->d;
	}
}

//free all memory in the linklist
void cleanList(linkList *ll){
	node *temp = ll->head;
	while(temp != NULL){
		free(temp->d);
		node *tempnext = temp->next;
		free(temp);
		temp = tempnext;
	}
	free(ll);
}

//reverse the elements of the linklist
void reverseList(linkList *ll){
	node *prev = NULL;
	node *next;
	node *temphead = ll->head;
	
	while (temphead != NULL) {
	    next = temphead->next;
	    temphead->next = prev;
	    if(prev == NULL) ll->tail = temphead;
	    prev = temphead;
	    temphead = next;
	}
	ll->head = prev;
}

//search for element in linkList, if found remove.
void searchRemoveFirst(linkList *ll,char *first){
	node *temp = ll->head;
	node *prev = temp;
	data *tempdata;
	while(temp != NULL){
		if(strcmp(temp->d->first,first) == 0){
			//element found!
			if(temp == ll->head){
				tempdata = popFront(ll);
				prev = ll->head;
			} else if(temp == ll->tail){
				tempdata = popBack(ll);
			} else {
				prev->next = temp->next;
				temp->next = NULL;
				tempdata = temp->d;
			}
			free(tempdata);
			free(temp);
			if(prev == NULL) temp = prev;
			else temp = prev->next;
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
}
void searchRemoveLast(linkList *ll,char *last){
	node *temp = ll->head;
	node *prev = temp;
	data *tempdata;
	while(temp != NULL){
		if(strcmp(temp->d->last,last) == 0){
			//element found!
			if(temp == ll->head){
				tempdata = popFront(ll);
				prev = ll->head;
			} else if(temp == ll->tail){
				tempdata = popBack(ll);
			} else {
				prev->next = temp->next;
				temp->next = NULL;
				tempdata = temp->d;
			}
			free(tempdata);
			free(temp);
			if(prev == NULL) temp = prev;
			else temp = prev->next;
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
}

void searchRemoveAge(linkList *ll,int age){
	node *temp = ll->head;
	node *prev = temp;
	data *tempdata;
	while(temp != NULL){
		if(temp->d->age == age){
			//element found!
			if(temp == ll->head){
				tempdata = popFront(ll);
				prev = ll->head;
			} else if(temp == ll->tail){
				tempdata = popBack(ll);
			} else {
				prev->next = temp->next;
				temp->next = NULL;
				tempdata = temp->d;
			}
			free(tempdata);
			free(temp);
			if(prev == NULL) temp = prev;
			else temp = prev->next;
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
}

void searchRemoveID(linkList *ll,int id){
	node *temp = ll->head;
	node *prev = temp;
	data *tempdata;
	while(temp != NULL){
		if(temp->d->id == id){
			//element found!
			if(temp == ll->head){
				tempdata = popFront(ll);
				prev = ll->head;
			} else if(temp == ll->tail){
				tempdata = popBack(ll);
			} else {
				prev->next = temp->next;
				temp->next = NULL;
				tempdata = temp->d;
			}
			free(tempdata);
			free(temp);
			if(prev == NULL) temp = prev;
			else temp = prev->next;
		} else {
			prev = temp;
			temp = temp->next;
		}
	}
}
