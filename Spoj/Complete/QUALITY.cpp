#include <iostream>

using namespace std;

void score (int a, int b, int c, int d, int e, int f, int count);

int main()
{
	int a, b, c, d, e, f;

	int count = 0;
	while (cin >> a) {
		cin >> b >> c >> d >> e >> f;
		count ++;
		score(a, b, c, d, e, f, count);
	}

	//while (true)
	//cin >> a;
	return 0;
}

void score (int a, int b, int c, int d, int e, int f, int count)
{
	int solved = 0;
	int time = 0;

	if (a > 0) {
		solved ++;
		if (d > 1) {
			time += 1200*(d-1);
		}
		time += a;
	}
	if (b > 0) {
		solved ++;
		if (e > 1) {
			time += 1200*(e-1);
		}
		time += b;
	}

	if (c > 0) {
		solved ++;
		if (f > 1) {
			time += 1200*(f-1);
		}
		time += c;
	}

	cout << "team " << count << ": " <<  solved << ", " << time << endl; 
}

