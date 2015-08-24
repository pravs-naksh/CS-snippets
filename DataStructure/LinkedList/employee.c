#include "employee.h"

/* This function will open a file for reading. Then it will load the data for each employee into a data element and load it into a linkList. Finally the linkList is returned. */
linkList* loadData(char *fileName){
	FILE *inputFile = fopen(fileName,"r");
	if(inputFile == NULL){
		printf("Error opening input file %s\n",fileName);
		exit(1);
	}
	
	linkList *newlinkList = createlinkList();
	
	char first[128];
	char last[128];
	int id;
	int age;
	while (fscanf(inputFile, "%s", first) != EOF) {
			fscanf(inputFile, "%s", last);
			fscanf(inputFile, "%d", &age);
			fscanf(inputFile, "%d", &id);
			data *tempData = createData(first,last,age,id);
            addFront(newlinkList,tempData);
            //addBack(newlinkList,tempData);
    }
    fclose(inputFile);
    return newlinkList;
}

/* This function will count everyone in the linkList who has the same first name as the input variable first. The counted number is returned. */
int countFirstName(linkList *ll, char *first){
	int size = listSize(ll);
	searchRemoveFirst(ll,first);
	int newSize = listSize(ll);
	if(size > newSize){
		return size - newSize;
	}
	return 0;
}

/* This function will remove from the linkList anyone who has the same last name as the input variable last. After calling this function be sure to print out the linkList again. */
void removeLastName(linkList *ll, char *last){
	searchRemoveLast(ll,last);
	printList(ll);
}

