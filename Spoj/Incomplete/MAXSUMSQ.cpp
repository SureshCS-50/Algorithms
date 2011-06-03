#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void Sum (vector <int> v, long int s, long int k);

int minimum = INT_MIN;
int cnt = 0;

vector <bool> x;

int main ()
{
	int N, T, y;
	vector <int> v;
	
	cin >> T;

	for ( int i = 0; i < T; i ++ ) {
		cin >> N;
		long int s = 0;
		long int k = 0;
		//int minimum = -9999999;
		for ( int i = 0; i < N; i ++ ) {
			scanf("%d", &y);
			v.push_back(y);
		}
		x.assign(v.size(),false);
		Sum(v, s, k);
		printf("%d %d\n", minimum, cnt);
		minimum = INT_MIN;
		cnt = 0;
		v.clear();
		x.clear();
	}

	return 0;
}

void Sum (vector <int> v, long int s, long int k)
{

	x[k] = true; 
	
	if (s+v[k] == minimum) cnt++;
	if (s + v[k] > minimum){
		minimum = s + v[k];
		cnt = 0;
	} else if (k < v.size()-1) {
		Sum (v, s, k+1);
	}

	x[k] = false;

	if (k < v.size()-1) {
		Sum (v, s, k+1);
	}
}