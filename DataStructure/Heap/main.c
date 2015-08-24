#include "heapApp.h"

#define DEBUG 1

int main(int argc, char* argv[])
{
	char* file = argv[1];
	heap *newHeap = getData(file);
	
	printf("\n-----------10 Co-ordinates nearest to origin----------------\n");
	printHeap(newHeap);
	cleanHeap(newHeap);
	
  	return 0;
}
