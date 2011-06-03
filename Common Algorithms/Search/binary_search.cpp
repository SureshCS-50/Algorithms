#include <iostream>

using namespace std;

int binary_search ( int A[], int x ) ;

int main () 
{
	int A[10];
	int x;
	int pos;

	for ( int i = 0; i < 10; i ++ ) {
		A[i] = i * i ;
	}

	cout << "Enter the no. to be searched for: \t";
	cin >> x;

	pos = binary_search ( A, x );

	if ( pos == -1 ) {
		cout << "no. x isn't present in the array" << endl;
	} else {
		cout << "no. is present in the array" << endl;
		cout << "Position of the no x is " << pos + 1 << endl;
	}

	return 0; 
}

int binary_search ( int A[], int x )
{
	int mid;
	int first = 0;
	int last = 9;

	if ( x == A[0] ) {
		return first;
	}

	if ( x == A[9] ) {
		 return last;
	}

	while ( first < last ) {
		mid = ( first + last ) / 2;

		if ( x == A[mid] ) {
			return mid;
		} else if ( x < A[mid] ) {
			last =  mid ;
		} else if ( x > A[mid] ) {
			first = mid ;
		}
		if ( last - first == 1 ) {
		       break;
		}	       
	}

	return -1; 
}





	



