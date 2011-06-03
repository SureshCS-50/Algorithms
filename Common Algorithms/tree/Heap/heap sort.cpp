#include <iostream>
#include <vector>

#define SIZE 11

using namespace std;

void max_heapify ( vector <int> &a, int i, int );
void build_max_heap ( vector <int> &a );
void heap_sort ( vector <int> &a );
void display ( vector <int> a );

int main ()
{
	vector <int> a;

	int x;

	a.push_back ( 0 );
	for ( int i = 1; i < SIZE; i ++ ) {
		cin >> x;
		a.push_back ( x );
	}

	heap_sort(a);

	display ( a );

	return 0;

}

void max_heapify ( vector <int> &a, int i, int heap_size )
{
	int l;
	int r;
	int largest;

	l = 2 * i;
	r = 2 * i + 1;

	if ( l <= heap_size && a[l] > a[i] ) {
		largest = l;
	} else {
		largest = i;
	}
	if ( r <= heap_size && a[r] > a[largest] ) {
		largest = r;
	}

	if ( largest != i ) {
		int temp;
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
	
		max_heapify ( a, largest, a.size() - 1 );
	}
	
}

void display ( vector <int> a ) 
{
	for ( int i = 1; i < (int)a.size (); i ++ ) {
		cout << a [i] << endl;
	}
}

void build_max_heap ( vector <int> &a )
{
	int heap_size = a.size() - 1;
	for ( int i = heap_size / 2 ; i >= 1; i -- ) {
		max_heapify ( a, i, a.size() );
	}
}

void heap_sort ( vector <int> &a )
{
	build_max_heap ( a );
	for ( int i = (int) a.size() - 1; i >= 2; ) {
		int temp;
		temp = a [1];
		a[1] = a [i];
		a[i] = temp;
		i--;
		max_heapify ( a, 1, i );
	}
}

