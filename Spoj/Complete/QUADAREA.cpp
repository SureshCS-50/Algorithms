#include <iostream>
#include <cmath>

using namespace std;

/*CYCLIC QUADRILATERAL has MAXIMUM AREA*/

int main()
{
	int T;
	double s, a, b, c, d, A;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >> a >> b >> c  >> d;
		s = ((double)a +(double)b + (double)c + (double)d)/2.0;
		A = (double)sqrt((s-(double)a)*(s-(double)b)*(s-(double)c)*(s-(double)d));
		printf ("%.2lf\n", A);
	}

	

	return 0;
}
