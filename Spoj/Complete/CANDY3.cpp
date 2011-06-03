#include <iostream>
#include <vector>

#define lint unsigned long long 
using namespace std;

int main()
{
	lint T, N, x, s=0;
	cin >> T;
	for (lint i = 0; i < T; ++i) {
		s = 0;
		cin >> N;
		for (lint j = 0; j < N; ++j) {
			cin >> x;
			s = (s%N + x%N)%N;
		}
		if (s == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}