#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int * arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
};

void fisherYates(int * arr, int len){
	int i, j, rndIdx;
	for(i=len-1; i>=1; i--){
		j = rand() % len;
		swap(arr, i, j);
	};

	};
int main(int argc, char* argv[]){
	int i, len = argc-1;
	int *arr = (int*)malloc(len*sizeof(int)); 
	srand(time(NULL));
	for(i=1; i<argc; i++){
		arr[i-1]=atoi(argv[i]);
		
	};
	
	fisherYates(arr, len);
	for(i=0;i<len; i++){
		printf("%d ", arr[i]); 
	};
	printf("\n");
	free(arr);
	return 0;
};

