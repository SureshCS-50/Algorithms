#include <iostream>
#include <vector>

#define SIZE 11

using namespace std;

void max_heapify ( vector <int> &a, int i, int );
//void build_max_heap ( vector <int> &a );
//void heap_sort ( vector <int> &a );
void display ( vector <int> a );
void increment_key ( vector <int> &a, int i, int val );
void enqueue ( vector <int> &a, int val, int heap_size );
int size ( vector <int> a );
int maximum ( vector <int> a, int heap_size );
int dequeue ( vector <int> &a, int heap_size );

int main ()
{
	vector <int> a;

	int x;

	a.push_back ( 0 );
	for ( int i = 1; i < SIZE; i ++ ) {
		cin >> x;
		a.push_back ( x );
	}

	enqueue ( a, 0, 10 );
	cout << endl;
	display ( a );

	cout << endl;
	cout << endl;

	cout << dequeue ( a, 12); 

	cout << endl;
	cout << endl;

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
	cout << endl;
	for ( int i = 1; i < (int)a.size (); i ++ ) {
		cout << a [i] << endl;
	}
}
/*
void build_max_heap ( vector <int> &a )
{
	int heap_size = a.size() - 1;
	for ( int i = heap_size / 2 ; i >= 1; i -- ) {
		max_heapify ( a, i, a.size() );
	}
}
*/
void increment_key ( vector <int> &a, int i, int val )
{
	int temp;
	a[i] = val;
	if ( i/2 > 0 && val >= a[i/2] ) {
		temp = a[i/2];
		a[i/2] = a[i];
		a[i] = temp;
		i = i/2;
		increment_key ( a, i, val );
	}
}

void enqueue ( vector <int> &a, int val, int heap_size )
{
	a.push_back ( val );
	heap_size ++;
	increment_key ( a, heap_size, val );
}

int size( vector <int> a )
{
	return ( a.size() - 1 );
}

int maximum ( vector <int> a, int heap_size )
{
	if ( heap_size == 0 ) {
		return -1;
	} else {
		return a [1];
	}
}

int dequeue ( vector <int> &a, int heap_size ) 
{
	int max;

	max = a[1];

	a[1] = a[heap_size];
	heap_size--;
	max_heapify ( a, 1, heap_size );
	a.pop_back();

	return max;
}
