#include "heapApp.h"

#define DEBUG 0

heap* getData(char *file){
	FILE* input_file = fopen(file,"r");
	if(input_file == NULL){
		printf("Error opening input file %s\n",file);
		exit(1);
	}
	float inputx = 0.0;
	float inputy = 0.0;	
	heap *newheap = createHeap();
	int i = 0;
	while(fscanf(input_file, "%f", &inputx) != EOF){
		fscanf(input_file, "%f", &inputy);
		data *d= createData(inputx,inputy);
		d->distance = calculateDistance(d->valx,d->valy);
		if(i>9){
			if(d->distance < newheap->root->d->distance){
				leaf *removeleaf = removeRoot(newheap);
#if DEBUG
				printf("deleted : %f and inserted : %f -- \n",removeleaf->d->distance,d->distance);
#endif
				popBack(newheap->q->ll);
				free(removeleaf->d);
				free(removeleaf);
				addLeaf(newheap,d);
			} else {
#if DEBUG			
				printf("Skipped : %f => ",d->distance);
				printf("deleting ...... \n");
#endif
				free(d);
			}
		}
		else { 	
#if DEBUG		
			printf("inserted : %f -- \n",d->distance);
#endif
			addLeaf(newheap,d);
		}
		i++;
	}
	
	fclose(input_file);
	return newheap;
}


void printHeap(heap *h){
	data **listCor = (data**)malloc(sizeof(data*)*10);
	int i = 0;
	while(h->root){
		if(i>9){
			popBack(h->q->ll);
			break;
		}
		leaf *rootleaf = removeRoot(h);
		
#if DEBUG		
		printf("removing data %f at %d \n",rootleaf->d->distance,i);
#endif
		
		listCor[i] = createData(rootleaf->d->valx,rootleaf->d->valy);
		listCor[i]->distance = calculateDistance(listCor[i]->valx,listCor[i]->valy);
		
		if(h->root == rootleaf){
			free(h->root->d);
			free(h->root);
			h->root = NULL;
		} else {
			free(rootleaf->d);
			free(rootleaf);
		}

		popBack(h->q->ll);
		i++;	
	}
	
	for(i = 9;i>=0;i--){
		printf(" %.2f %.2f %.2f \n",listCor[i]->distance,listCor[i]->valx,listCor[i]->valy);
		data *d = createData(listCor[i]->valx,listCor[i]->valy);
		d->distance = calculateDistance(d->valx,d->valy);
		addLeaf(h,d);
		free(listCor[i]);
	}
	
	free(listCor);
}

float calculateDistance(float x,float y){
	return floorf((sqrt((x*x) + (y*y))) * 100 + 0.5) / 100;
}
