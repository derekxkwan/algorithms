#include <stdio.h>
#include <stdlib.h>
void swap(int * arr, int i, int j){
	int temp;
	temp = arr[i];
	arr[i]=arr[j];
	arr[j] = temp;
	
};


void quickSort(int * arr , int len){
	if(len <= 1){
		return;
	}
	else{
		int i, j;
		i = 1;
		for(j=1;j<len;j++){
			if(arr[j] < arr[0]){
				swap(arr, i, j);
				i++;
				};
		//swap pivot into rightful place
		swap(arr, i-1, 0);
		quickSort(arr, i-1);
		quickSort(arr+i, len - i);
		};

	};

};


int main(int argc, char* argv[]){
	int len,i;
	len = argc-1;
	int *arr = (int*)malloc(len *sizeof(int)); 
	for(i=1; i<argc; i++){
		arr[i-1]=atoi(argv[i]);
	};
	
	quickSort(arr, len);
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	};
    printf("\n");
	free(arr);
	return 0;
};

