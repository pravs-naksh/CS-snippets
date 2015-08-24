#include "analyzeData.h"

tree* readData(char *file){
	tree* new_tree = createTree();
	FILE* input_file = fopen(file,"r");
	if(input_file == NULL){
		printf("Error opening the file: %s\n",file);
	}
	
	float input = 0.0;
	while (fscanf(input_file,"%f",&input) != EOF)
	{
//			printf("data to be inserted: %f\n",input);
			data* new_data = createData(input);
			addLeaf(new_tree,new_data);
	}
	fclose(input_file);
    return new_tree;
}

float* makeArray(tree* t){
	int size = treeSize(t);
	float* arr = (float*)malloc(sizeof(float)*size);
	int i = 0;
	queue *new_queue = createQueue();
	addtoQueue(new_queue,t->root);
	if(new_queue->ll->head){
		node* temp = NULL;
		temp = new_queue->ll->head;
		while(temp != NULL){
				//arr[i] = (float*)malloc(sizeof(float));
				arr[i] = temp->d->d->val;
				i++;
				temp = temp->next;
		}
	}
	queueClean(new_queue);
	return arr;
}

void addtoQueue(queue* q,leaf* l){
	if(l == NULL) return;
	queuePush(q,l);
	if(l->left) addtoQueue(q,l->left);
	if(l->right) addtoQueue(q,l->right);
}

void printArray(float *arr, int size){
	int i;
	for(i=0;i<size;i++){
		printf("%f\n",arr[i]);
	}
}

void insertionSort(float* arr, int size){
	
	int i, j;
	for (i = 1; i < size; i++) { 
		// 1. Take the second element from the array list and compare it with 1st 
		// Eg: 1st element = 7, 2nd element = 5 
		// 2. Now check if the 1st element is larger than second, if true SWAP them. 
		// Now, compare array[0]>array[1] => 7 > 5 = TRUE,hence SWAP!
		if (arr[i - 1] > arr[i]) {
			// 3. Now keep checking till we reach 1st location in the array.
			for (j = i; j > 0; j--) {
			// 4. Now check if the current element is larger than previous, if true SWAP them.
				if (arr[j - 1] > arr[j]) {
				//Call to swap function which will swap the elements in array
#if DEBUG
									printArray(arr,size);
									printf(" ==> ");
#endif
									swap(arr, j - 1, j);
#if DEBUG
									printArray(arr,size);
									printf(": %d is greater than %d\n", arr[j - 1], arr[j]);
#endif 
				}
			}
		// 5. Now, continue repeating 1-4 till we reach the end of the array.
		}
	}
}

void swap(float* array, int a, int b){
	float temp;
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
