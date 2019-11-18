#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

clock_t start, stop;

void dgemm_blas(long double **X, long double **Y, long double **R, long int n){
for( int i =0; i<n; i++)
		for(int j =0; j<n; j++){
			R[i][j] = 0;
			for(int k =0; k<n; k++)
			R[i][j] += X[i][k] * Y[k][j]; 
	}
}
int main(){
	start = clock();
	long int n;
	srand(time(0));
	printf("\n Enter matrix size: \n");
	scanf("%lld", &n);
	long double **Y = (long double**)malloc(n*sizeof(long double*));
	long double **X = (long double**)malloc(n*sizeof(long double*));
	long double **R = (long double**)malloc(n*sizeof(long double*));
	for( int i = 0; i<n; i++){
		Y[i] = (long double*)malloc(n*sizeof(long double));
		X[i] = (long double*)malloc(n*sizeof(long double));
		R[i] = (long double*)malloc(n*sizeof(long double));
	}
	for (long int i = 0; i<n;i++){
		printf("\n");
		for (long int j = 0; j<n; j++){
			Y[i][j] = rand()%100 + 0.001 * (rand()%100);
			X[i][j] = rand()%100 + 0.001 * (rand()%100);
	printf("%llf ", X[i][j]);
	}}
	printf("\n\n");
	for (int i =0; i<n; i++){
		printf("\n");
		for (int j=0; j<n; j++){
		printf("%llf ", Y[i][j]);
	}}
	printf("\n\n");
/*
	for( int i =0; i<n; i++)
		for(int j =0; j<n; j++){
			R[i][j] = 0;
			for(int k =0; k<n; k++)
			R[i][j] += X[i][k] * Y[k][j]; 
	}*/
	dgemm_blas(X,Y,R,n);
	for (int i =0; i<n; i++){
		printf("\n");
		for (int j=0; j<n; j++){
		printf("%llf ", R[i][j]);
	}}
	printf("\n\n");
	
	stop = clock();
	double timeresult_clock = (double)(stop-start)/CLOCKS_PER_SEC;
	printf("\n\n timeresult = %6.10lf \n", timeresult_clock);
	return 0;
}
