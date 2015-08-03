#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int left[], int right[], int mid, int rest){
	int i =0, j=0, k=0;
	while(i<mid && j<rest){
		if(left[i] <= right[j]){
			arr[k++] = left[i++];
			}
		else{
			arr[k++] = right[j++];
			};
		};
	while(i<mid){
		arr[k++] = left[i++];
	};
	while(j<rest){
		arr[k++] = right[j++];
	};

	};
void mergeSort(int arr[], int len){
	int mid, rest;
	int *left, *right;
	if(len <= 1){
		return;
	}
	else{
		mid = len/2;
		rest = len-mid;
		left = (int*)malloc(mid*sizeof(int));
		right = (int*)malloc((rest)*sizeof(int));
		for(int i=0;i<mid;i++){
			left[i] = arr[i];
			};
		for(int i=0;i<rest;i++){
			right[i] = arr[i+mid];
		};
		mergeSort(left, mid);
		mergeSort(right, rest);
		merge(arr, left, right, mid, rest);
		free(left);
		free(right);
	};
	
};

int main(int argc, char* argv[]){
	int len = argc-1;
	int *arr = (int*)malloc(len*sizeof(int)); 
	for(int i=1; i<argc; i++){
		arr[i-1]=atoi(argv[i]);
		
	};
	
	mergeSort(arr, len);
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	};
	printf("\n");
	free(arr);
	return 0;
};
