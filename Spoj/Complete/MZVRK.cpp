#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

string whirligig (string s);
string dec2bin(long long num);

int main ()
{

	long long a, b;
	char bufferA[33];
	char bufferB[33];
	string s, s1;
	long long sum = 0;
	vector <string> v;

	vector <long long> powers(65);

	long long p = 1;
	for (int i = 0; i < 65; ++i) {
		powers[i] = p;
		p*=2;
	}

	cin >> a >> b;
	//scanf ("%ld",&b);

	long long i = a;
	if (a%2!=0) {sum ++;i=a+1;}
	if (b%2!=0) sum ++;
	sum += (b-a)/2;
	for (; i <= b; i += 2) {
		sum += i&-i;
	}
	if (a%2 != 0 && b%2 != 0) --sum;
	cout << sum << endl;
	return 0;

}
