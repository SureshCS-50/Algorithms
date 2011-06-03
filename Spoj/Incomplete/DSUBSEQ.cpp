#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define lint unsigned long long

using namespace std;

lint dsubseq (string s);

int main()
{
	lint T;
	cin >> T;
	vector <lint> ans;
	string s;

	for (lint i = 0; i < T; ++i) {
		cin >> s;
		for (lint j = 0; j < s.length(); ++j) {
			if (s[j] == '\r') {s.erase(s.begin()+j);--j;}
		}
		ans.push_back(dsubseq(s));
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	
	return 0;
}

lint dsubseq (string s)
{
	lint num = 1000000007;
	vector <lint> dsubseqs(s.length()+1,0);

	dsubseqs[0] = 1;

	for (lint i = 0; i < s.length(); ++i) {
		if (count(s.begin(),s.begin()+i, s[i]) == 0) {
			dsubseqs[i+1] = (dsubseqs[i]*2);
		} else {
			lint c = 0;
			for (lint j = i-1; j >= 0; --j) {
				if (s[i] == s[j]) {c = dsubseqs[j];break;}
			}
			dsubseqs[i+1] = (dsubseqs[i]*2 - c);
		}
		if (dsubseqs[i+1] < 0) while (true);
		if (dsubseqs[i+1] >= num) while (dsubseqs[i+1]>=num) dsubseqs[i+1] -= num;
	}
	while (dsubseqs[s.length()]>=num) dsubseqs[s.length()] -= num;
	return (dsubseqs[s.length()]%num);
}
