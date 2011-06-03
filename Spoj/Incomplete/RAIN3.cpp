#include <iostream>
#include <vector>
#include <climits>

#define lint long long
using namespace std;

int main() 
{
	lint T, i, j, N, s, t, M;

	lint a, b, c, d, e, f;
	a = 78901;
	b = 31;
	c = 699037;
	d = 23456;
	e = 64;
	f = 2097151;

	vector <lint> sq;
	vector <lint> sum;
	cin >> T;
	for (i = 0; i < T; ++i) {
		cin >> s >> t >> N >> M;
		sq.assign(N,0);
		sum.assign(N,0);
		for (j = 0; j < N; ++j) {
			s = (a + b*s)%c;
			t = (d + e*t)%f;
			sq[j] = (s%100 + 1)*(t%100 + 1);
			if (j == 0) sum[0] = sq[0];
			else sum[j] = sum[j-1] + sq[j];
		}

		lint p, q;
		p = 0;
		q = 1;
		lint lth = sq.size();
		lint maxLength = 0;
		lint minLength = INT_MAX;
		while (q < lth && p < lth) {
			if (sum[q] - sum[p] + sq[p] <= M) q++;
			else {
				if (q-p < minLength) minLength = q-p;
				++ p;
			}
		}
		if (q-p < minLength) maxLength = q-p;

		if (minLength == INT_MAX) minLength = 0;
		cout << minLength << endl;
	}

	return 0;
}

