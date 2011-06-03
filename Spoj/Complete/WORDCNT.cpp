#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main() 
{
	int n;
	cin >> n;

	int prev_size = 0;
	int cnt = 0;
	vector <int> v;
	string s;

		getline(cin, s);
	while (n--) {
		getline(cin, s);
		
		stringstream str(s);
		string temp;

		while (str >> temp) {
			if ((int)temp.size() == prev_size) {
				cnt ++;
			} else {
				v.push_back(cnt);
				prev_size = temp.size();
				cnt = 1;
			}
		}
		v.push_back(cnt);
		s.clear();
		cnt = 0;
		prev_size = 0;

		cout << *max_element(v.begin(), v.end()) << endl;
		v.clear();
	}


	return 0;
}


