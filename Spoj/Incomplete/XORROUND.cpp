#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int T, N, K;
	int num[510],newnum[501];
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> K;
		for (int j = 0; j < N; ++j) {
			cin >> num[j];
		}
		for (int j = 0; j < K; ++j) {
			newnum[0] = (num[0]^num[1])^num[N-1];
			for (int k = 1; k < N-1; ++k) {
				newnum[k] = (num[k]^num[k-1])^num[k+1];
			}
			newnum[N-1] = (num[N-1]^num[N-2])^num[0];
			for (int k = 0; k < N; ++k) {
				num[k] = newnum[k];
			}
		}
		for (int j = 0; j < N; ++j) {
			cout << num[j] << " ";
		}
		cout << endl;
	}
	return 0;
}

