#include <iostream>
#include <vector>

using namespace std;

void check (int n, vector <int> &N, vector <int> &D);

int main()
{
	int x;
	vector <int> N;
	vector <int> D;
	vector <int> v;

	while(cin >> x) {
		if (x == 0) {
			break;
		}
		v.push_back(x);
	}

	for (int i = 0; i < (int)v.size(); i ++) {
		check(v[i], N, D);
	}
	return 0;
}

void check (int n, vector <int> &N, vector <int> &D)
{
	int x = n;
	if (x==1) {
		cout << "1/1" << endl;
		return;
	} else if (x==2) {
		cout << "1/2" << endl;
		return;
	} else if (x==3) {
		cout << "2/1" << endl;
		return;
	}

	int r = 0;
	int back_index;
	int back_rem;
	vector <int> rem;
	vector <int> index;
	//vector <int> :: reverse_iterator rit;

	while(true) {
		r = x % 2;
		x = x/2;
		rem.push_back(r);
		index.push_back(x);
		if (x <= 3) {
			break;
		}
	}

	//for (rit=index.rbegin() ; rit < index.rend(); ++rit) {
	//	if (*rit == 2) {
	//		if (rem.back() == 1) {


		if (index.back() == 2) {
  			N.push_back(-1);
			N.push_back(1);
			N.push_back(1);
			D.push_back(-1);
			D.push_back(1);
			D.push_back(2);			
		}
		if (index.back() == 3) {
			N.push_back(-1);
			N.push_back(1);
			N.push_back(1);
			N.push_back(2);
			D.push_back(-1);
			D.push_back(1);
			D.push_back(2);
			D.push_back(1);
		}
		while(index.size()>0) {
			back_index = index.back();
			back_rem = rem.back();
			index.pop_back();
			rem.pop_back();
			//treeIndex = (2*back_index) + back_rem;
			if (back_rem == 0) {
				N.push_back(N.back());
				D.push_back(N.back()+D.back());
			} else {
				N.push_back(N.back()+D.back());
				D.push_back(D.back());
			}
		}
		cout << N.back() << "/" << D.back() << endl;
}
