#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int first, int last){
	int i,j, randIdx, temp, pivot, n = last-first+1;
	if(n>1){
		randIdx = (rand() % n)+first;
		temp = arr[randIdx];
		arr[randIdx] = arr[last];
		arr[last] = temp;
		pivot = arr[last];
		i = first;
		for(j = first; j<last; j++){
			if(arr[j] < pivot){
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				i = i + 1;
			};

		};
		temp = arr[i];
		arr[i] = pivot;
		arr[last] = temp;
		quickSort(arr, first, i-1);
		quickSort(arr, i+1, last);

	};


};

int main(int argc, char* argv[]){
	int i, len = argc-1;
	int *arr = (int*)malloc(len*sizeof(int));
	for (i=1; i<argc; i++){
		arr[i-1]=atoi(argv[i]);
	};
	srand(time(NULL));
	quickSort(arr, 0, len -1);
	for(i=0;i<len; i++){
		printf("%d ", arr[i]);

	};
	printf("\n");
	free(arr);
	return 0;

};
