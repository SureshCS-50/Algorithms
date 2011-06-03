/*
 * Program for insertion sort
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2

int main () 
{
	int x;
	int size;
	int capacity;
	int *A = malloc ( N * sizeof ( int ) );
	int i;
	int j;
	int k;
	clock_t c0;
	clock_t c1;

	capacity = N;
	size = 0;

	printf("Enter no. to be inserted ( 0 to terminate )");
	scanf("%d", &x);


	while ( x != 0 ) {

		c0 = clock();
		if ( size == capacity ) {
			A = realloc ( A, capacity * 2 * sizeof (int) );
			capacity = capacity * 2;
		}

		i = -1;

		while ( i < size-1 && x > A[i+1] ) {
			i++;
		}
	
		for ( k = size - 1; k > i; k-- ) {
			A[k+1] = A[k];
		}

		A[i+1] = x;
		
		size++;
			
		c1 = clock();
	
		printf("TIME %f\n", (float) (c1 - c0) / CLOCKS_PER_SEC);
		printf("enter x : ");
		scanf("%d", &x);

	}

	for ( j = 0; j < size; j++ ) {

		printf("%d", A[j]);
		printf("\n");

	}

	return 0; 
}








