#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

clock_t start, stop;

void saxpy_blas(long long int* X, long long int* Y, long long int n, long long int a){
	for( int i=0;i<n;i++){
		Y[i]=a*X[i]+Y[i];
	}
}

int main(){
	start = clock();
	long long int *Y;
	long long int *X;
	long long int a;
	long long int n;
	srand(time(0));
	printf("\n Enter vector size: \n");
	scanf("%lld", &n);
	printf("\n Enter a: \n");
	scanf("%lld", &a);
	Y = (long long int*)malloc(n*sizeof(long long int));
	X = (long long int*)malloc(n*sizeof(long long int));
	for( int i = 0; i<n; i++){
		Y[i] = rand() % 100;
		X[i] = rand() % 100;
	printf("%lld ", X[i]);
	}
	printf("\n\n");
	for (int i =0; i<n; i++){
	printf("%lld ", Y[i]);
	}
	printf("\n\n");
/*	for( int i=0;i<n;i++){
	Y[i]=a*X[i]+Y[i];
	}*/
	saxpy_blas(X,Y,n,a);
	for (int i =0; i<n; i++){
	printf("%lld ", Y[i]);
	}
	printf("\n\n");
	free(Y);
	free(X);
	stop = clock();
	double timeresult_clock = (double)(stop-start)/CLOCKS_PER_SEC;
	printf("\n\n timeresult = %6.10lf \n", timeresult_clock);
	return 0;
}
