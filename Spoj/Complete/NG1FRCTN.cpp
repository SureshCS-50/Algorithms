#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//bool next2next (int x, int y);
//bool next (int x, int y);
//bool findDigits(int x, int y);
//void send (int a, int b, vector <int> &N, vector <int> &D);
void check (int n, vector <int> &N, vector <int> &D);
void lowest (vector <int> Nx, vector <int> Dx);
//int length (int x);

int main()
{
	int x, y;
	vector <int> N;
	vector <int> D;
	vector <int> A;
	vector <int> B;

	while(cin >> x) {
		cin >> y;
		if (x == 0 && y == 0) {
			break;
		}
		A.push_back(x);
		B.push_back(y);
	}

	for (int i = 0; i < (int)A.size(); i ++) {
		vector <int> temp1;
		vector <int> temp2;
		check(A[i], N, D);
		temp1.push_back(N.back());
		check(B[i], N, D);		
		temp2.push_back(D.back());
		lowest(temp1, temp2);
	}

	
	return 0;
}

void check (int n, vector <int> &N, vector <int> &D)
{
	int x = n;
	if (x==1) {
		N.push_back(1);
		D.push_back(1);
		return;
	} else if (x==2) {
		N.push_back(1);
		D.push_back(2);
		return;
	} else if (x==3) {
		N.push_back(2);
		D.push_back(1);
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
		//cout << N.back() << "/" << D.back() << endl;
}

/*
void send (int a, int b, vector <int> &N, vector <int> &D)
{
	int x = a;
	int y = b;

	if ( (x==1) && (y==1) ) {
		cout << "1/1" << endl;
		return;
	}

	if ( (x==1) && (y==2) ) {
		cout << "1/2" << endl;
		return;
	}
	if ( (x==1) && (y==3) ) {
		cout << "1/1" << endl;
		return;
	}
	if (findDigits(x, y)) {
		vector <int> temp1;
		vector <int> temp2;
		check(x, N, D);
		temp1.push_back(N.back());
		check(y, N, D);
		temp2.push_back(D.back());
		lowest(temp1, temp2);
	}

	if (next2next(x, y)) {		
		int l1 = length(x);
		int l2 = length(y);
		vector <int> Nx;
		vector <int> Dx;

		check(x, N, D);
		Nx.push_back(N.back());
		int den_x = D.back();

		if(x != pow((float)2,l1-1)) {
			check(pow((float)2, l1)-1, N, D);
			Dx.push_back(D.back());
		} else {
			Dx.push_back(den_x);
		}	

		for (int i = 0; i < l2-l1-1; i ++) {
			check(pow((float)2, l1), N, D);
			Nx.push_back(N.back());
			check(pow((float)2, (l1+1))-1, N, D);
			Dx.push_back(D.back());
		}

		check(pow((float)2,(l2-1)), N, D);
		Nx.push_back(N.back());
		check(y, N, D);
		Dx.push_back(D.back());

		lowest(Nx, Dx);
	}

	if(next(x, y)) {
		//cout << "DSSSSSSSSSSSS";
		int l1 = length(x);
		int l2 = length(y);
		vector <int> Nx;
		vector <int> Dx;

		check(x, N, D);
		Nx.push_back(N.back());
		int den_x = D.back();

		if(x != pow((float)2, l1)-1) {
			check(pow((float)2, l1)-1, N, D);
			Dx.push_back(D.back());
		} else {
			Dx.push_back(den_x);
		}
		//cout << "PULKIT MANHOOS";
		check(pow((float)2, (l2-1)), N, D);
		Nx.push_back(N.back());
		//cout << "PULKIT MANHOOS";
		if (y == pow((float)2, (l2-1))) {
			Dx.push_back(D.back());
		} else {			
			check(y, N, D);
			Dx.push_back(D.back());
		}
//   		cout << "PULKIT MANHOOS";
		lowest(Nx, Dx);
	}
}


bool findDigits(int x, int y)
{
	int count = 0;
	int count1 = 0;
	
	while (x>0) {
		x /= 2;
		++count;
	}
	
	while (y>0) {
		y /= 2;
		++count1;
	}

	if (count == count1) {
		return true;
	}

	return false;
}

int length (int x)
{
	int count = 0;
	
	while (x>0) {
		x /= 2;
		++count;
	}

	return count;
}

bool next (int x, int y)
{
	int count = 0;
	int count1 = 0;
	
	while (x>0) {
		x /= 2;
		++count;
	}
	
	while (y>0) { 
		y /= 2;
		++count1;
	}

	if ((count1-count) == 1) {
		return true;
	}

	return false;
}

bool next2next (int x, int y)
{
	int count = 0;
	int count1 = 0;
	
	while (x>0) {
		x /= 2;
		++count;
	}
	
	while (y>0) {
		y /= 2;
		++count1;
	}

	if ((count1-count) > 1) {
		return true;
	}

	return false;
}
*/
void lowest (vector <int> P, vector <int> Q)
{
	int num, den;
	num = den =1;
	for (int i = 0; i < P.size(); ++i) {
		num *= P[i];
	}
	for (int i = 0; i < Q.size(); ++i) {
		den *= Q[i];
	}
	int small;
	if (num < den) {
		small = num;
	} else {
		small = den;
	}

	for (int i = small; i > 1; --i) {
		if (num%i == 0 && den%i == 0) {
			num /= i;
			den /= i;
			if (num < den)
				i = num+1;
			else 
				i = den+1;
		}
	}
	cout << num << "/" << den << endl;
}
