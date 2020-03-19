#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define num 100
void merge(int *A,int p,int q,int r){
	int n1=q-p+1;
	int n2=r-q;
	int *L,*R;
	L=(int*)malloc((n1+1) * sizeof(int));
	R=(int*)malloc((n2+1) * sizeof(int));
	int i,j;
	for(i=0;i<n1;i++){
		L[i]=A[p+i];	
	}
	for(j=0;j<n2;j++){
		R[j]=A[q+j+1];
	}
	L[n1]=100000;
	R[n2]=100000;
	i=0;j=0;
	int k=p;
	for(k=p;k<=r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else {
			A[k]=R[j];
			j++;
		}
	}
}


void merge_sort(int *A,int p,int r){
	if(p<r){
		int q=(r+p)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
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
	int p=0,r=num-1;
	merge_sort(A,p,r);
	for(i=0;i<num;i++){
		printf("%d\n",A[i]);
	}
	
} 
