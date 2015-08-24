#include "employee.h"

int main(int argc, char* argv[])
{
  char* filename = argv[1];
  linkList *ll = loadData(filename);
  int count = countFirstName(ll,"Jason");
  printf("count is %d\n",count);
  reverseList(ll);
  searchRemoveAge(ll,25);
  removeLastName(ll,"Haining");
  cleanList(ll);
  return 0;
}
