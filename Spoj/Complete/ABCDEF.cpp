#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, x;
	int v[100];
	vector <int> sex1;

	cin >> N;

	for (int i = 0; i < N; i ++) {
		cin >> x;
		v[i] = x;
	}

	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			for (int k = 0; k < N; k ++) {
				sex1.push_back((v[i]*v[j])+v[k]);					
			}
		}
	}

	int occur = 0;
	sort(sex1.begin(), sex1.end());
	vector <int> :: iterator low, up;
	int num;
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < N; j ++) {
			for (int k = 0; k < N; k ++) {
				if (v[k] != 0) 
				{
					num = (v[i]+v[j])*v[k];
					up = upper_bound(sex1.begin(), sex1.end(), num);
					low = lower_bound(sex1.begin(), sex1.end(), num);
					occur += int(up - low);
				}
			}
		}
	}
	
	cout << occur << endl;
	
	return 0;
}
