#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct group {
	int start;
	int end;
};

void findMinGrps(int K, string s, int count);
vector <group> findGroups (int K, string s);
string removeGroup (string s, group g);

vector <int> ans;
int minimum = 65535;

int main()
{
	int N, K;
	string s;

	cin >> N >> K;

	cin >> s;

	findMinGrps(K,s,0);

	if (ans.size() == 0) {
		cout << -1;
		return 0;
	}
	cout << minimum;
	return 0;
}

void findMinGrps(int K, string s, int count)
{
	if (count >= minimum) return;

	if (s.length() == 0) {
		if (count<minimum) {
			minimum = count;
			ans.push_back (count);
		}
		return;
	}
	vector <group> groups = findGroups (K, s);
	if (groups.size() == 0) {
		return;
	}

	for (int i = groups.size()-1; i >= 0; --i) {
		string temp = removeGroup(s, groups[i]);
		findMinGrps(K, temp, count+1);
	}
	
}

vector <group> findGroups (int K, string s)
{
	int count = 1;
	int start;
	group temp;
	vector <group> ans;
	start = 0;
	int i;
	for (i = 1; i < s.length(); i ++) {
		if (s[i] == s[i-1]) {
			count++;
		}
		else {
			if (count >= K) {
				temp.start = start;
				temp.end = i-1;
				ans.push_back(temp);
			}
			count = 1;
			start = i;
		}
	}

	if (count >= K) {
		temp.start = start;
		temp.end = i-1;
		ans.push_back(temp);
	}

	return ans;
}

string removeGroup (string s, group g)
{
	
	s.erase(s.begin()+g.start, s.begin()+g.end+1);
	return s;
}
