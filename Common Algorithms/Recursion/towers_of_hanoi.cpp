#include <iostream>

#define SIZE 3

using namespace std;

void tower ( int n, char from, char to, char aux );

int main ()
{
	char A, B, C;

	A = 'A';
	B = 'B';
	C = 'C';
	
	tower ( SIZE, A, C, B );
	cin >> A;

	return 0;

}

void tower ( int n, char from, char to, char aux )
{
	if ( n == 1 ) {
	cout << "Transferring " << n << " from " << from << " to " << to << endl;
	} else {
		tower ( n - 1, from, aux, to );
		
		cout << "Transferring " << n << " from " << from << " to " << to << endl;
		
		tower ( n - 1, aux, to, from );
	}
}
