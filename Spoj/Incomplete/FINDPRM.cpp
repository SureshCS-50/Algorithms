#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>

#define MAX 10000000

using namespace std;

bool isprime[MAX/3];
bool isRevPrime[MAX];

void make_primes2()
{
	int i,j,lim=sqrt((double)MAX);

	bool bit1=1,bit2;

	for(i=5;i<=lim;i+=bit1?2:4,bit1=!bit1)
	{
		if(!isprime[i/3])
		{
			bit2=1;
			for(j=i;;)
			{
				j+=bit2?i<<2:i<<1;
				bit2=!bit2;
				if(j>=MAX)break;
				isprime[j/3]=1;
			}
		}
	}
}

void reverse_sieve(int n)
{
	int rt = sqrt((double)n);
	for (int i = 0; i <= n; isRevPrime[i++]=1)
		;
	isRevPrime[1] = 0;
	for (int i = n; i >=0; --i) {
		if (isRevPrime[i]) {
			for (int j = 2; j <= rt; j++) {
				if (i%j==0) {
					isRevPrime[j] = 0;
					isRevPrime[i/j] = 0;
				}
			}
		}
	}
}

int main()
{
	make_primes2();
	isprime[0] = 1;
	int T,cnt,N;
	scanf("%d",&T);//cin >> N;
	for (int i = 0; i < T; ++i) {
		cnt = 0;
		scanf("%d",&N);//cin >> N;
		reverse_sieve(N);
		if (N >= 2 && isRevPrime[2]) cnt++;//cout << "2 is prime" << endl;}
		if (N >= 3 && isRevPrime[3]) cnt++;//cout << "3 is prime" << endl;}
		if (N >= 5 && isRevPrime[5]) cnt++;//cout << "5 is prime" << endl;}
		for (int k = 1; 6*k+1 <= N; ++k) {
			if (6*k+1 <= N && !isprime[2*k] && isRevPrime[6*k+1]) cnt++;//cout << 6*k+1 << " is prime" << endl;}
			if (6*k+5 <= N && !isprime[2*k+1] && isRevPrime[6*k+5]) cnt++;//cout << 6*k+5 << " is prime" << endl;}
		}
		printf("%d\n",cnt);
	}

	return 0;
}

