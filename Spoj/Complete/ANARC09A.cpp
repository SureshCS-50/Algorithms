#include <iostream>
#include <string>

using namespace std;

int conversions(string s);

int main()
{
	string input;

	int i = 1;
	while (true)
	{
		cin >> input;
		if (input[0] == '-') return 0;
		else cout << i++ << ". " << conversions(input) << endl;
	}
}

int conversions(string s)
{
	int openingCount = 0;
	int closingCount = 0;
	int changes1 = 0;
	int changes2 = 0;
	int j = s.length()-1;
	for (int i = 0; i < s.length(); ++i,--j) {
		if (s[i] == '{') openingCount ++;
		else openingCount--;
		if (s[j] == '}') closingCount ++;
		else closingCount--;
//		cout << closingCount << " " << openingCount;
		if (openingCount < 0) {changes1++;openingCount = 1;}
		if (closingCount < 0) {changes2++;closingCount = 1;}
	}

//	cout << endl << endl << (changes1+openingCount) << " " <<(changes2+closingCount) << endl << endl;
/*
	if (changes1 == 0 && changes2 == 0) return 0;
	else if (changes1 == 0 && changes2 != 0) return changes2;
	else if (changes1 != 0 && changes2 == 0) return changes1;
	else return (changes1+changes2);*/
	return ((changes1+openingCount/2)<(changes2+closingCount/2)?(changes1+openingCount/2):(changes2+closingCount/2));
}