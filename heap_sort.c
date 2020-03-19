#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#define num 10
int num=10;
void max_heapify(int *A,int i){
	int l,r;
	l=2*i;
	r=2*i+1;
	int largest=i;
	
	if(l<=num&&A[l-1]>A[i-1]){
		largest=l;
	}
	if(r<=num&&A[r-1]>A[largest-1]){
		largest=r;
	}
	int term=0;
	printf("%d,",largest);
	if(largest!=i){
		term=A[i-1];
		A[i-1]=A[largest-1];
		A[largest-1]=term;
		max_heapify(A,largest);
	}
}

void build_max_heap(int *A){
	int i;
	for(i=num/2;i>0;i--){
		max_heapify(A,i);
	}
}
void heapsort(int *A){
	build_max_heap(A);
	int i;
	int term;
	for(i=num;i>=2;i--){
		term=A[0];
		A[0]=A[i-1];
		A[i-1]=term;
		num--;
		max_heapify(A,1);
	}
}
int main(){
	int *A;
	A = (int*)malloc(num * sizeof(int));
	srand(time(NULL));
	int i;
	for(i=0;i<num;i++){
		A[i]=rand()%11;
		printf("%d\n",A[i]);
	}
	printf("\n");
	heapsort(A);
	for(i=0;i<num;i++){
		printf("%d\n",A[i]);
	}
} 


