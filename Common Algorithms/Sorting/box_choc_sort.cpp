#include <iostream>

using namespace std;

#define N 10

struct box {
	int val;
	int choc;
	int index;
};

int main () 
{
	struct box b[N];
	int x;
	int max;

	cin >> x;
	
	for ( int i = 0; i < x; i ++ ) {
		cin >> b[i].val >> b[i].choc;
		b[i].index = i;
	}

	for ( int i = 0; i < x; i++ ) {
		for ( int j = i + 1; j < x; j ++ ) {
			if ( b[i].val > b[j].val ) {
				struct box temp;
				temp = b[i];
				b[i] = b[j]; 
				b[j] = temp;
			} else if ( b[i].val == b[j].val ) {
				if ( b[i].choc > b[j].choc ) {
					;
				} else {
					struct box temp1;
					temp1 = b[j];
					b[j] = b[i];
					b[i] = temp1;
				}
			}
		}
	}
	/*			int max;
					
				max = b[i];




				if ( b[i] > b[j] ) {
					max = b[i];
				} else {
					max = b[j];
				}
			}
		}
	}*/

	cout << endl;
	for ( int i = 0; i < x; i ++ ) {
		cout << b[i].index;
		cout << "\t";
	}
	return 0; 
}


