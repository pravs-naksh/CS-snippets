#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include "linklist.h"

/* This function will open a file for reading. Then it will load the data for each employee into a data element and load it into a linkList. Finally the linkList is returned. */
linkList* loadData(char *fileName);

/* This function will count everyone in the linkList who has the same first name as the input variable first. The counted number is returned. */
int countFirstName(linkList *ll, char *first);

/* This function will remove from the linkList anyone who has the same last name as the input variable last. After calling this function be sure to print out the linkList again. */
void removeLastName(linkList *ll, char *last);

#endif