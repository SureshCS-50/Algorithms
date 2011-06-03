#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void sieve (int N);
bool isPrime[1000000000]={0};
int main()
{
	int T, m, n;
	int max = 0;
	vector <int> A;
	vector <int> B;


	cin >> T;

	for (int k = 0; k < T; ++k) {
		cin >> m >> n;
		A.push_back(m);
		B.push_back(n);
		if (n > max) max = n;
	} 
	sieve(max);
	isPrime[0] = 1;
	isPrime[1] = 1;
	
	int count = 0;
	for (int i = 0; i < (int)A.size(); ++i) {
		count = 0;
		for (int j = A[i]; j <= B[i]; ++j) {
			if (!isPrime[j]) {
				cout << j << endl;
			}
		}
		cout << endl;
	}
//	while(true);
	return 0;
}

void sieve (int N)
{
	int x=sqrt((double)N);   
     
	for (int i = 4; i <= N; i += 2) {   
         isPrime[i]=1;   
	}
	
	for (int i = 3; i <= x; i += 2) {
         if (!isPrime[i])  
         {
            for (int j = i*i; j <= N; j += 2*i)   
                isPrime[j]=1;   
         }
	}
}

