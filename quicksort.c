#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define num 100
int partition(int *A,int p,int r){
	int x=A[r-1];
	int i=p-1;
	int j;
	int term;
	for(j=p;j<r;j++){
		if(A[j-1]<x){
			i++;
			term=A[j-1];
			A[j-1]=A[i-1];
			A[i-1]=term;
		}
	}
	term=A[i+1-1];
	A[i+1-1]=x;
	A[r-1]=term;
	return i+1;
}

void quick_sort(int *A,int p,int r){
	if(p<r){
		int q;
		q=partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
	
}

int main(){
	int *A;
	A = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	int a;
	for(a=0;a<num;a++){
		A[a]=rand()%11;
		printf("%d\n",A[a]);
	}
	quick_sort(A,1,num);
	for(a=0;a<num;a++){
		printf("%d\n",A[a]);
	}
}