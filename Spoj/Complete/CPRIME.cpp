#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

bool isPrime[100000000] = {0};

void sieve(int N);
double theorem (int x);

struct numbers {
	int x;
	int index;
	int till_now;
};

bool compare (numbers n1, numbers n2) {
	return (n1.x < n2.x);
}

bool compare1 (numbers n1, numbers n2) {
	return (n1.index < n2.index);
}
int main() 
{
	numbers num;
	vector <numbers> n;
	int max = 0;
	vector <int> v;

	isPrime[0] = 1;
	isPrime[1] = 1;
	isPrime[2] = 0;
	isPrime[3] = 0;
	int in = 0;
	while (cin >> num.x) {
		if (num.x == 0) {
			break;
		}
		num.index = in;
		in ++;
		num.till_now = 0;
		n.push_back(num);
		if (num.x > max) {
			max =num.x;
		}
	}
	sieve(max);
	sort (n.begin(), n.end(), compare);
	int cnt = 0;
	for (int j = 0; j <= n[0].x; ++j) {
		if (isPrime[j] == 0) {
			cnt ++;
		}
	}
	//cout << cnt << endl;
	n[0].till_now = cnt;
	for (int i = 1; i < (int)n.size(); ++i) {
		cnt = 0;
		for (int j = n[i-1].x+1; j <= n[i].x; ++j) {
			if (isPrime[j] == 0) {
				cnt ++;
			}
		}
		n[i].till_now = n[i-1].till_now + cnt;	
		//cout << n[i].till_now << endl;
	}
	sort (n.begin(), n.end(), compare1);
	for (int i = 0; i < (int)n.size(); ++i) {
		printf("%.1lf\n", (abs((double)n[i].till_now - theorem(n[i].x))*100.0/(double)n[i].till_now));		
	}

	return 0;
}

void sieve(int N)   
{   
     int x=sqrt(N),i,j;   
        
         for (i=4;i<=N;i+=2)   
           isPrime[i]=1;   
	 for (i=3;i<=x;i+=2) {  
                if (!isPrime[i]) {
		   for (j=i*i;j<=N;j+=2*i) {
			   isPrime[j]=1;
		   }
		}
	 }
}

double theorem (int x)
{
	return ((double)x/log(double(x)));
}