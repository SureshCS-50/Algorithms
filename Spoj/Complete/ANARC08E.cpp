#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int x, y;

	vector <int> inX, inY;
	vector <bool> ans;

	cin >> x >> y;

	while (x != -1 && y != -1) {
		inX.push_back (x);
		inY.push_back (y);
		if (x==1 || y ==1) {
			ans.push_back (true);
		} else {
			ans.push_back (false);
		}
		cin >> x >> y;
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << inX[i] << "+" << inY[i];
		if (ans[i]) {
			cout << "=";
		} else {
			cout << "!=";
		}
		cout << inX[i]+inY[i] << endl;
	}
	return 0;
}