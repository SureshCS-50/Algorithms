#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

void score (vector <int> X, vector <int> Y);
double slope (int a, int b, int c, int d);

int main ()
{
	int T, x, y;
	vector <int> X, Y;

	while (cin >> T) {
		if (T == 0) {
			break;
		}
		for (int i = 0; i < T; ++i) {
			cin >> x >> y;
			X.push_back(x);
			Y.push_back(y);
		}
		score(X, Y);
		X.clear();
		Y.clear();
	}

	return 0;
}

void score (vector <int> X, vector <int> Y)
{
	set <double> ans;
	float m;
	for (int i = 0; i < (int)X.size(); ++i) {
		for (int j = i+1; j < (int)Y.size(); ++j) {
			m = slope(X[i], Y[i], X[j], Y[j]);

			ans.insert(m);
		}
	}

	cout << ans.size() << endl;
}
double slope (int x1, int y1, int x2, int y2) 
{
	if (x2 != x1) {
		return (double)((double)y2-(double)y1)/(double)((double)x2-(double)x1);
	} else if ((y2-y1)>0){
		return INT_MAX;
	} else if ((y2-y1)<0){
		return -INT_MAX;
	} else {
		return 10*INT_MAX;
	}
}
