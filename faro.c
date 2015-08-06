#include <stdio.h>
#include <stdlib.h>
void faro(int arr[], int len){
	int i =0, j, k =0, mid;
	int *arrTmp = (int*)malloc(len*sizeof(int));
	mid = len/2;
	j = mid;
	while(i < mid && j < len){
	arrTmp[k++] = arr[i++];
	arrTmp[k++] = arr[j++];
	};
	for(i=0; i< len; i++){
	arr[i] = arrTmp[i];
	};
	free(arrTmp);
};

int main(int argc, char * argv[]){
	int i, len = argc-1;
	int *arr = (int*)malloc(len*sizeof(int)); 
	for(i=1; i<argc; i++){
		arr[i-1]=atoi(argv[i]);
		
	};
	faro(arr,len);
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	};
	printf("\n");
	free(arr);
	return 0;

};
