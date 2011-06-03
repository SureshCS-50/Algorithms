#include <iostream>
#include <algorithm>
#include <vector>

#define N 10

using namespace std;

void merge ( vector <int> &a, int, int, int );

void merge_sort ( vector <int> &a, int, int );

void display ( vector <int> a );

int main () 
{
	vector <int> a;

	for ( int i = 0; i < N; i++ ) {
		a.push_back( i + 1 );
	}

	random_shuffle ( a.begin(), a.end() );

	merge_sort ( a, 0, N - 1 );

	cout << "Sorted array is :: \n";
	display ( a );

	return 0; 
}

void merge ( vector < int >  &a, int p, int q, int r ) 
{
	int s[N];
	int nl;
	int nr;
	int il;
	int ir;

	il = 0;
	ir = 0;
	nl = q + 1 - p;
	nr = r - q;

	while ( il < nl && ir < nr ) {
		if ( a[ p + il ] <= a[ q + 1 + ir ] ) {
			s[ il + ir ] = a[ p + il ];
			il++;
		} else {
			s[ il + ir ] = a[ q + 1 + ir ];
			ir++;
		}
	}

	while ( il < nl ) {
		s[ il + ir ] = a[ p + il ];
		il++;
	}

	while ( ir < nr ) {
		s[ il + ir ] = a[ q + 1 + ir ];
		ir++;
	}

	for ( int i = 0; i < il + ir ; i++ ) {
		a[p + i] = s[i];
	}
}

void merge_sort ( vector < int > &a, int p, int r )
{
	int q;

	if ( p < r ) {
		q = ( p + r )/2;
	
		merge_sort ( a, p, q );
		merge_sort ( a, q + 1, r );

		merge ( a, p, q, r );
	}
}

void display ( vector < int > a )
{
	for ( int i = 0; i < N; i++ ) {
	       cout << a[i] << endl;
	} 
}

