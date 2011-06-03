#include <iostream>

using namespace std;

int main () 
{
	int A[10];

	cout << "Enter the list of nos. you want to be sorted :\n";
	for ( int i = 0 ; i < 10 ; i ++ ) {
	       cin >> A[i];
	}	

	for ( int i = 0 ; i < 10 ; i ++ ) {
		for ( int j = i + 1 ; j < 10 ; j ++ ) {
			if ( A[i] > A[j] ) {
				int x;

				x = A[i];
				A[i] = A[j];
				A[j] = x;
			}
		}
	}

	cout << "\nNos. in the Sorted order \n";

	for ( int i = 0; i < 10; i ++ ) {
		cout << A[i] << endl;
	}

	return 0; 
}

