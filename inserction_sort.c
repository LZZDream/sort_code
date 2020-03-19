#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define num 100
int main(){
	int *A;
	A = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	int a;
	for(a=0;a<num;a++){
		A[a]=rand()%11;
		printf("%d\n",A[a]);
	}
	int i=1;
	int j=0;
	for(i=1;i<num;i++){
		int key=A[i];
		j=i-1;
		while(j>=0&&A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
	}
	printf("\n");
	for(a=0;a<num;a++){
		printf("%d\n",A[a]);
	}
	free(A);
}

