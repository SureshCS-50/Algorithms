#include <iostream>
#include <vector>
                              
using namespace std;

void max_heapify ( vector < int > &, int, int );
void build_max_heap ( vector < int > & , int );
void heap_sort ( vector < int > &, int );
void display ( vector < int > );

int main () 
{
	vector < int > v;
	int x;
	int heap_size;

	do {
		cin >> x;
		v.push_back(x);
	} while ( x!= 0 );

	v.pop_back();
	
	heap_size = v.size();

	heap_sort ( v, heap_size );
	
	display ( v );

	return 0; 
}

void max_heapify ( vector < int > &v, int i, int heap_size )
{
	int left;
	int middle;
	int right;
	int largest;	

	left = 3 * i + 1;
	middle = 3 * i + 2; 
	right = ( 3 * i ) + 3;

	if ( heap_size > left && v [left] > v[i] ) {
		largest = left;
	} else {
		largest = i;
	}

	if ( heap_size > middle && v [middle] > v [largest] ) {
	       largest = middle;
	}

	if ( heap_size > right && v [right] > v [largest] ) {
	       largest = right;
	}

	if ( largest != i ) {
		int temp;

		temp = v[largest];
		v[largest] = v[i];
		v[i] = temp;

		max_heapify ( v, largest, heap_size );
	}
}

void build_max_heap ( vector < int > &v, int length )
{
	for ( int i = length/3; i >= 0; i -- ) {
		max_heapify ( v, i, length );
	}
}

void heap_sort ( vector < int > &v, int length )
{
	build_max_heap ( v, length );

	for ( int i = length - 1; i > 0; i -- ) {
		int temp;

		temp = v[0];
		v[0] = v[i];
		v[i] = temp;

		length --;
		max_heapify ( v, 0, length );
	}
}

void display ( vector < int > v ) 
{
	for ( int i = 0; i < ( int ) v.size(); i ++ ) {
		cout << v[i];
		cout << endl;
	}
}
