#include "tree.h"

tree* readData(char *file);

float* makeArray(tree* t);

void addtoQueue(queue* q,leaf* l);

void printArray(float *arr, int size);

void insertionSort(float* arr, int size);

void swap(float array[], int a, int b);
