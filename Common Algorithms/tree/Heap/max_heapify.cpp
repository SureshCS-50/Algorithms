#include <iostream>
#include <vector>

using namespace std;

void max_heapify ( vector < int > &, int, int );
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

	max_heapify ( v, 1, heap_size );

	display ( v );

	return 0; 
}

void max_heapify ( vector < int > &v, int i, int heap_size )
{
	int left;
	int right;
	int largest;	

	left = 2 * i + 1;
	right = ( 2 * i ) + 1 + 1;

	if ( heap_size > left && v [left] > v[i] ) {
		largest = left;
	} else {
		largest = i;
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

void display ( vector < int > v ) 
{
	for ( int i = 0; i < ( int ) v.size(); i ++ ) {
		cout << v[i];
		cout << endl;
	}
}

