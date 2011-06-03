#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

void sieveOfAtkin (int N);
bool isPrime[86028040] = {0};

int main() 
{
	int Q, x;
    static int a[5000000];
    scanf("%d", &Q);
	vector <int> v(Q);

	for (int i = 0; i < Q; ++i) {
		scanf("%d", &x);
		v[i] = x;
	}
	
	sieveOfAtkin(86028040);

	isPrime[0] = 0;
	isPrime[1] = 0;
	isPrime[2] = 1;
	isPrime[3] = 1;
	isPrime[4] = 0;

	int cnt = 0;
	for (int i = 2; i < 86028040; ++i ) {
		if (isPrime[i] == 1) {
			cnt ++;
			a[cnt] = i;
		}
	}

	for (int i = 0; i < Q; ++i) {
		printf("%d\n", a[v[i]]);
	}
	
	//while(true);
	return 0;
}


void sieveOfAtkin(int limit)  
{  
     int x=sqrt((double)limit);
     long long n, i, j, ii, jj;
     for (i = 1; i < x; ++i) {
         for (j = 1; j < x; ++j) {
             ii = i*i;
             jj = j*j;
             n = (ii<<2) + jj;
             if ((n <= limit) && ((n%12 == 1) || (n%12 == 5))) {
                 isPrime[n] = !isPrime[n];
             }
             n = n-ii;
             if ((n <= limit) && (n % 12 == 7)) {
                 isPrime[n] = !isPrime[n];
             }
             n = n-jj-jj;
             if ((i > j) && (n <= limit) && (n % 12 == 11)) {
                 isPrime[n] = !isPrime[n];
             }
         }
     }
     for (i = 5; i < x; ++i) {
         if (isPrime[i]) {
             long long sqI = i*i;
             for (j = sqI; j <= limit; j += sqI) {
                 isPrime[j] = 0;
             }
         }
     }
}

