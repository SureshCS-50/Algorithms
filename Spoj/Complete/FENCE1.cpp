#include <iostream>

using namespace std;
#define pi 3.14159265358979323846264338327950288

int main ()
{
	int T;

	while (cin >> T) {
		if (T == 0) {
			break;
		}
		printf("%.2lf\n", (double)T*T/2.0/(double)(pi));
	}

	//cin >> T;
	return 0;
}