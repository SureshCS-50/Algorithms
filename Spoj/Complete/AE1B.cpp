#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare (int i, int j){
	if (i < j) {
		return false;
	}
	return true;
}
int main()
{	
	int n, k, s, temp;
	vector <int> v;

	cin >> n >> k >> s;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		v.push_back(temp);	
	}
	
	int require = k*s;
	sort(v.begin(), v.end(), compare);

	int sum = 0;
	for (int i = 0; i < (int)v.size(); ++i) {
		sum += v[i];
		if (sum >= require) {
			cout << i+1 << endl;
			break;
		}
	}
	//while(true);

	return 0;
}