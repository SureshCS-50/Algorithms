#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int calc (int n, int k, int l);
vector <int> fib(32) ;
int digit[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int main()
{
    int n;
    int k;
    int l;
    int t;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n >> k >> l;
		printf("%d\n", calc(n, k, l));
    }
    return 0;
}

int calc (int n, int k, int l) {

	int dig = digit[k];
	if (l < n) {
		return l%dig;
	}
	queue <int> lastNFibs;
	fib[n] = 0;
	for (int i = 0; i < n; ++i) {
		fib[i] = i;
		fib[n] += fib[i];
		if (fib[i] > dig) {
			fib[i] %= dig;
		}
		if (fib[n] > dig) {
			fib[n] %= dig;
		}
		lastNFibs.push(fib[i]);
	}
	
	lastNFibs.push(fib[n]);
	int fibonacci;
	for (int i = n+1; i <= l; i++) {
		fibonacci = lastNFibs.back() - lastNFibs.front() + lastNFibs.back();
		
		if (fibonacci > dig) {
			fibonacci %= dig;
		}
		
		lastNFibs.pop();
		lastNFibs.push(fibonacci);
	}
	return lastNFibs.back();
}
