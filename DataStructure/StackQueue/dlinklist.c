#include "dlinklist.h"


dlinklist* createlinklist()
{
  dlinklist* ll = (dlinklist*)malloc(sizeof(dlinklist));
  ll->head = NULL;
  ll->tail = NULL;
  return ll;
}


node* createNode(data *d)
{
  node *n = (node*)malloc(sizeof(node));
  n->d = d;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

data* createData(char val)
{
  data *d = (data*)malloc(sizeof(data));
  d->val = val;
  return d;
}

void addFront(dlinklist *ll,data *d){
	node *newnode = createNode(d);
        if(ll->head == NULL && ll->tail == NULL)
          {
            ll->head = newnode;
            ll->tail = newnode;
          }
        else 
          {
            newnode->next = ll->head;
	    ll->head->prev = newnode;
            ll->head = newnode;
          }
}

//create a new node, set the data pointer, and add to back of dlinklist
void addBack(dlinklist *ll,data *d){
	node *newnode = createNode(d);
        if(ll->head == NULL && ll->tail == NULL)
          {
            ll->head = newnode;
            ll->tail = newnode;
          }
        else 
          {
                ll->tail->next = newnode;
		newnode->prev = ll->tail;
                ll->tail = newnode;
          }
}

//print values in the data structures in the dlinklist
void printList(dlinklist *ll){
	node *temp = ll->head;
        
        while(temp != NULL){
                printf("%c\n",temp->d->val);
                temp = temp->next;
        }
}

//count the number of elements in the dlinklist and return the count
int listSize(dlinklist *ll){
	node *temp = ll->head;
        int size = 0;
        while(temp != NULL){
                size++;
                temp = temp->next;
        }
        return size;
}

//remove node from the front of the list and return the data element
data* popFront(dlinklist *ll){
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
	    ll->head->prev = NULL;
            return deltemp->d;
          }
}
//remove node from the front of the list and return the data element
data* popBack(dlinklist *ll){
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
		node *deltemp = ll->tail;
		ll->tail = ll->tail->prev;
		ll->tail->next = NULL;
                return deltemp->d;
        }
}
//free all memory in the dlinklist
void cleanList(dlinklist *ll){
	node *temp = ll->head;
        while(temp != NULL){
                free(temp->d);
                node *tempnext = temp->next;
                free(temp);
                temp = tempnext;
        }
        free(ll);
}
//reverse the elements of the dlinklist
void reverseList(dlinklist *ll){
	//node *prev = NULL;
        node *next;
        node *temphead = ll->head;
        
        while (temphead != NULL) {
            next = temphead->next;
            temphead->next = temphead->prev;
            if(temphead->prev == NULL) ll->tail = temphead;
            temphead->prev = temphead;
            temphead = next;
        }
        ll->head = temphead->prev;
}

//search for element in dlinklist, if found remove.
void searchRemove(dlinklist *ll,char val){
	node *temp = ll->head;
       // node *prev = temp;
        data *tempdata;
        while(temp != NULL){
                if(temp->d->val == val){
                        //element found!
                        if(temp == ll->head){
                                tempdata = popFront(ll);
                                //prev = ll->head;
                        } else if(temp == ll->tail){
                                tempdata = popBack(ll);
                        } else {
                                temp->prev->next = temp->next;
                                temp->next = NULL;
                                tempdata = temp->d;
                        }
                        free(tempdata);
                        free(temp);
                        if(temp->prev == NULL) temp = temp->prev;
                        else temp = temp->prev->next;
                } else {
                        //prev = temp;
                        temp = temp->next;
                }
        }
}
