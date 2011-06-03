#include <iostream>
#include <vector>

using namespace std;

int main () 
{
	vector < string > v;
	string s;
	int size;
	int N;
	int i;
	int j;
	int k;
	

	cin >> N;

	v.assign ( N, "" );

	size = 0;

	for ( int j = 0; j < N; j ++ ) {
		cin >> s;
		
		i = -1;
		while ( i < size-1 && s > v[i+1] ) {
			i++;
		}
	
		for ( k = size - 1; k > i; k-- ) {
			v[k+1] = v[k];
		}

		v[i + 1] = s;
		size ++;
						
	}

	for ( j = 0; j < N; j++ ) {

		cout << v[j] << endl;
	}

	return 0; 
}
