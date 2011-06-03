#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

char getChar (int N);

int main()
{
	int N;
	vector <char> ans;
	while (cin >> N) {
		ans.push_back (getChar(N));
	}

	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;
}

char getChar (int N) 
{
	double ans = (sqrt((double)1+8.0*N)-1)/2.0;
	if (ans == (int)ans) {

		ans--;
	}
	return ((int)ans%26+'A');
}