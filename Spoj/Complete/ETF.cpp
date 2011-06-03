#include <iostream>
#include <vector>

using namespace std;

long long check(long long a);

int main()
{
	long long T, x;
	
	scanf("%lld", &T);

	vector <long long> v(T);

	for (long long i =0; i < T; ++i) {
		scanf("%lld", &x);
		v[i] = x;
	}
	for (long long j = 0; j < (long long)v.size(); j ++) {
		printf("\n%lld", check(v[j]));
	}

	

	return 0;
}

long long check(long long n) 
     { 
       long long result = n; 
       for(long long i=2;i*i <= n;i++) 
       { 
         if (n % i == 0) result -= result / i; 
         while (n % i == 0) n /= i; 
       } 
       if (n > 1) result -= result / n; 
       return result; 
     } 

/*
long long check(long long a)
{
	long long count = 0;

	for (long long i = 1; i <= a; ++i) {
		if(gcd(a, i) == 1) {
			count ++;
		}
	}

	return count;
}

long long gcd(long long a,long long b)
{
    long long c;
    while(true)  {
  		c = a%b;
  		if(c == 0)
	  	  return b;
  		
		a = b;
  		b = c;
	}

	return -1;
 }*/