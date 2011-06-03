#include <iostream>
#include <vector>

using namespace std;

struct points {
	int x;
	int y;
};

void number (int x, int y);

int main()
{
	int N;
	points point;
	vector <points> v;
	vector <int> final;

	cin >> N;

	for (int i = 0; i < N; i ++) {
		cin >> point.x >> point.y;
		v.push_back(point);
	}

	cout << endl;

	for (int i = 0; i < v.size(); i ++) {
		number(v[i].x, v[i].y);
	}	

	return 0;
}

void number (int x, int y)
{
	//if((x+y)%2 != 0) {
	//	cout << "No Number" << endl;
	//} else {
	if (x-2 == y || y == x) {
		if (x%2 == 0) {
			cout << x+y << endl;
		} else {
			cout << x+y-1 << endl;
		}
	} else {
		cout << "No Number" << endl;
	}
}
