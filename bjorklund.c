#include <stdio.h>
#include <stdlib.h>

#define EUCMAX(a,b) \
	({__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	 _a > _b ? _a : _b;})
#define EUCMIN(a,b) \
	({__typeof__ (a) _a = (a); \
	__typeof__ (b) _b = (b); \
	 _a < _b ? _a : _b;})


int main(int argc, char * argv[]){
	//n is first arg, k is second
	int i, r, n, k, m, ksize, msize;
	char * eucstr, *temp;
	if(argc != 3){
		printf("incorrect number of args\n");
		return 0;
		}
	else{
		n = atoi(argv[1]);
		k = atoi(argv[2]);
		};
	m = 8;
	n = 13;
	k = 5;
	r = EUCMIN(m,k);
	eucstr = malloc(n*sizeof(char));
	temp = malloc(n*sizeof(char));
	for(i=0; i<n;i++){
		if(i<k){
			eucstr[i] = '1';
			}
		else{
			eucstr[i] = '0';
			};
		};
	ksize = 1;
	msize = 1;
	while(r > 1){
		int kidx = 0;
		int midx = k*ksize;
		int tidx = 0;
		int j=0;
		while(tidx<n){
			if(kidx<(k*ksize)){
			for(j=0;j<ksize;j++){
				temp[tidx] = eucstr[kidx];
				tidx++;
				kidx++;
				};
			};
			if(midx<n){
				for(j=0;j<msize;j++){
					temp[tidx] = eucstr[midx];
					tidx++;
					midx++;
				};
			}
			

		};
		ksize++;
		if(m>=k){
			m = m-k;

			}
		else{
			int tint;
			tint = k;
			k = m;
			m = tint-m;
			msize++;
			};
		r = EUCMIN(m,k);
		for(i=0;i<n; i++){
			eucstr[i] = temp[i];
			};
		};
	for(i=0; i<n; i++){
		printf("%c ", eucstr[i]);
			};
		printf("\n");
	return 0;

}
