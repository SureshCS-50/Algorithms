#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main()
{
	int T;
	int n;
	cin >> T;
	char s[100];

	for (int i = 0; i < T; ++i) {
		scanf("%d\n",&n);
		map <string, int> m;
		
		for(int i = 0; i < n; ++i) {
			gets(s);
			m[s]++;
		}
		
		map < string,int > :: iterator it;
		for(it = m.begin(); it != m.end(); ++ it) {
			printf("%s %d\n",((*it).first).c_str(),(*it).second);
		}
	
		cout << endl;
	}
	return 0;
}