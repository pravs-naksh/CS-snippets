#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char first[128];
  char last[128];
  int age;
  int id;
}data;

typedef struct nodePtr
{
  struct nodePtr *next;
  data *d;
}node;

typedef struct
{
  node *head;
  node *tail;
}linkList;

//reserve space for a new linklist, set initial variables, and return linklist
linkList* createlinkList();

//reserve space for new node, set variables and return
node* createNode(data *d);

//reserve space for a new data struct,set variables and return
data* createData(char *first, char *last, int age, int id);

//create a new node, set the data pointer, and add to front of linklist
void addFront(linkList *ll,data *d);

//create a new node, set the data pointer, and add to back of linklist
void addBack(linkList *ll,data *d);

//print values in the data structures in the linklist
void printList(linkList *ll);

//count the number of elements in the linklist and return the count
int listSize(linkList *ll);

//remove node from the front of the list and return the data element
data* popFront(linkList *ll);

//remove node from the front of the list and return the data element
data* popBack(linkList *ll);

//free all memory in the linklist
void cleanList(linkList *ll);

//reverse the elements of the linklist
void reverseList(linkList *ll);

//search for element in linkList, if found remove.
void searchRemoveFirst(linkList *ll,char *first);
void searchRemoveLast(linkList *ll,char *last);
void searchRemoveAge(linkList *ll,int age);
void searchRemoveID(linkList *ll,int id);

#endif