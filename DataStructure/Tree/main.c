#include "analyzeData.h"

int main(int argc, char* argv[])
{
  char* input_string = argv[1];
  tree* newTree = readData(input_string);
  printf("leaf at tree->root->left->left: %f\n",newTree->root->right->d->val);
  float* arr = makeArray(newTree);
//  exit(-1);
  int size = treeSize(newTree);
 printf("Inorder:\n");
  inOrderPrint(newTree);
 printf("\nPreorder:\n");
  preOrderPrint(newTree);
 printf("\nPostorder:\n");
  postOrderPrint(newTree); 
 printf("-----\nBefore:\n");  
  printArray(arr,size);
  insertionSort(arr,size);
  printf("\nAfter sort:\n");
  printArray(arr,size);

  if(balancedTree(newTree))
	printf("Tree is balanced!\n");
  else
	printf("Tree is not balanced!\n");

  leaf* rem = removeRoot(newTree);
  free(rem->d);
  free(rem);
  preOrderPrint(newTree);
  printf("----\n");
  free(arr);
  cleanTree(newTree);  
  return 0;
}
