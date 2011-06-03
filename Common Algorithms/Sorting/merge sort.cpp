#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void merge_sort ( vector <int> &A, int p, int r );
void merge ( vector <int> &A, int p, int q, int r);
void display ( vector <int> &A, int n );

int main ()
{

	vector <int> A;

	ofstream fout ( "output1.txt" );

	for ( int j = 0; j < 100; j ++ ) {
		int i;
		for ( i = 0; i < 100 * ( j + 1 ); i++ ) {
			x = rand();
			a.push_back ( x );
		}
	
		t0 = clock();
		merge_sort ( A, 0, i - 1 );
		t1 = clock();
		
		fout << i << "  " << (t1 - t0)<< endl;
	
		a.clear();
	}
	cout << "Done";

	fout.close();		 
	
	cout << endl;

	return 0;
}

void merge ( vector <int> &A, int p, int q, int r )
{
	int il;
	int ir;
	int nl;
	int nr;

	vector <int> T(A.size());

	il = 0;
	ir = 0;
	nl = q - p + 1;
	nr = r - q;

	while ( ( il < nl ) && ( ir < nr ) ) {
		if ( A [ p + il ] <= A [ q + 1 + ir ] ) {

			T [ il + ir ] = A [ p + il ];
			il ++;

		} else {

			T [ il + ir ] = A [ q + 1 + ir ];
			ir ++;

		}
	}

	while ( il < nl ) {
		T [ il + ir ] = A [ p + il ];
		il ++;
	}

	while ( ir < nr ) {
		T [ il + ir ] = A [ q + 1 + ir ];
		ir ++;
	}

	il = 0;
	while ( il < r - p + 1 ) {
		A [ p + il ] = T [ il ];
		il ++;
	}

}
			      
void display ( vector <int> &A, int n )
{
	for ( int i = 0; i < n; i ++ ) {
		cout << A[i] << endl;
	}
	cout << endl;
}

void merge_sort ( vector <int> &A, int p, int r ) 
{
	int q;

	if ( p < r ) {
		
		q = ( p + r ) / 2;

		merge_sort ( A, p, q );
		merge_sort ( A, q + 1 , r );
		merge ( A, p, q, r );
	}
}
 
