#include <iostream>
#include <vector>

using namespace std;

int partition ( vector < int >  &a, int p, int r );

void quick_sort ( vector < int > &a, int p, int r );

int main ()
{
	vector < int > a;
	int x;

	cout << "Enter the 10 elts. in an array..\n";
	
	for ( int i = 0; i < 10; i++ ) {
		cin >> x;
		a.push_back ( x );
	}

	quick_sort ( a, 0, 9 );

	cout << endl;

	for ( int i = 0; i < 10; i ++ ) {
		cout << a[i] << endl;
	}
	cout << endl;
	cin >> x;

	return 0;
}

int partition ( vector < int > &a, int p, int r ) 
{
	int i;
	int x;
	int n;

	x = a[r];

	i = p - 1;

	for ( int j = p; j < r; j ++ ) {
		if ( a[j] <= x ) {
			int m;

			m = a[j];
			a[j] = a[i+1];
			a[i+1] = m;

			i++;
		}
	}

	n = a[i+1];
	a[i+1] = a[r];
	a[r] = n;

	return i+1;
}

void quick_sort ( vector < int > &a, int p, int r ) 
{
	int q;

	if ( r > p ) {
		q = partition ( a, p, r );

		quick_sort ( a, p, q - 1 );

		quick_sort ( a, q+1, r);
	}
}
