#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t, n;

	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
		string s1;
		for (int j = 0; j < n; ++j) {
			cin >> s1;
		}
		if ( n % 2 == 0) {
			cout << "lxh" << endl;
		} else {
			cout << "hhb" << endl;
		}
	}		

	//while(1);
	
	return 0;
}
