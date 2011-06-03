#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, i, j, maxn = 0, maxk = 0;

	cin >> T;

	int N[25];
	int K[25];
	float ** prob;
	//vector <int> N(T);
	//vector <int> K(T);
	
	for (i = 0; i < T; ++i) {
		cin >> N[i] >> K[i];
		if (maxn < N[i]) maxn = N[i];
		if (maxk < K[i]) maxk = K[i];
	}

	prob = new float*[maxn];
	for (i = 0; i < maxn; ++i) {
		prob[i] = new float[maxk];
	}
	//vector <vector <float> > prob(maxn, vector <float> (maxk,0));

	for (i = 0; i < maxk && i < 6; ++i) prob[0][i] = (float)100.0/6.0;

	for (i = 1; i < maxn; ++i) {
		for (j = i; j < maxk && j <= 6*(i+1); ++j) {
			if (j-1 >= 0) prob[i][j] += prob[i-1][j-1];
			if (j-2 >= 0) prob[i][j] += prob[i-1][j-2];
			if (j-3 >= 0) prob[i][j] += prob[i-1][j-3];
			if (j-4 >= 0) prob[i][j] += prob[i-1][j-4];
			if (j-5 >= 0) prob[i][j] += prob[i-1][j-5];
			if (j-6 >= 0) prob[i][j] += prob[i-1][j-6];
			prob[i][j] /= 6.0;
		}
	}

	for (i = 0; i < T; ++i) {
		printf ("%d\n", (int)prob[N[i]-1][K[i]-1]);
	}

	return 0;
}
