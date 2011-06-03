#include <iostream>
#include <string>

using namespace std;

int length[100001];
char v[100001][15];

bool rev_lt(int i1, int i2)
{
     int l1 = length[i1];
     int l2 = length[i2];
	int i = (l1<l2)?l1:l2;
	int j = 0;

	while (i>=0 && v[i1][l1-j] == v[i2][l2-j]) 
		i--,j++;

	if (i < 0 && l1<l2) return true;
	else if (i<0 && l1>=l2) return false;
	else return v[i1][l1-j] < v[i2][l2-j];
}

bool lt(int i1, int i2)
{
     int l1 = length[i1];
     int l2 = length[i2];

    int i = 0;
	while (v[i1][i]!='\0' && v[i2][i] != '\0' && v[i1][i] == v[i2][i]) 
		i++;

	if (i > l1 || i >l2) return l1<l2;
	else return v[i1][i] < v[i2][i];
}

int main()
{
	int T,j,i;
	char s[15];

	long long count = 0;
	
	scanf("%d", &T);
	for (i = 0; i < T; i ++) {
		scanf("%s", s);
		
		for (j = 0; s[j] != '\0'; ++j) {
            v[i][j] = s[j];
        }
		
        v[i][j] = s[j];
		length[i] = j-1;
		
		for (j = 0; j < i; ++j) {
			if (rev_lt(j,i)) {
				if (lt(i,j)) {
					count ++;
				}
			} else if (lt(j,i)) {
				count ++;
            }
		}
	}

    printf("%lld", count);
/*
	while (true)
	cin >> T;
*/
	return 0;
}

