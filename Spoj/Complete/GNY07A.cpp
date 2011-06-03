#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct word {
	int index;
	string text;
};

string mispell (int index, string &text);

int main()
{
	word w;
	int T;
	string s;
	vector <string> final;
	vector <word> v;

	cin >> T;

	for (int i = 0; i < T; i ++) {
		cin >> w.index >> w.text;
		v.push_back (w);
	}

	for (int i = 0; i < (int)v.size(); i ++) {
		s = mispell(v[i].index, v[i].text);
		final.push_back(s);
	}

	cout << endl;

	for (int i = 0; i < (int)final.size (); i ++) {
		cout << i+1 << " " << final[i] << endl;
	}

	return 0;
}
string mispell (int index, string &text)
{
	text.erase (index-1, 1);

	return text;
}