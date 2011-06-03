#include <iostream>
#include <vector>

using namespace std;

void check (vector <int> v);
int position (vector <int> v, int i);

int main()
{
	int T;
	int x;

	vector <vector <int> > v;
	vector <int> temp;

	while (true) {
		cin >> T;
		if (T == 0) {
			break;
		}
		for (int i = 0; i < T; i ++) {
			cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
		temp.clear();				
	}

	for (int i = 0; i < v.size(); i ++) {
		check(v[i]);
	}

//	cin >> T;

	return 0;
}

void check (vector <int> v)
{
	vector <int> inverse(v.size(), 0);

	for (int i = 0; i < (int)v.size(); i ++) {
		inverse[v[i]-1] = i+1;
	}

	if (inverse == v) {
		cout << "ambiguous" << endl;
	} else {
		cout << "not ambiguous" << endl;
	}
}

/*
int position (vector <int> v, int n)
{
	for (int j = 0; j < (int)v.size(); j ++) {
		if(v[j] == n) {
			return j+1;
		}
	}
	return -1;
}*/