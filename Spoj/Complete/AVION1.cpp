#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    bool flag = false;

    for (int i = 1; i < 6; ++i) {
    	cin >> s;
    	if (s.find("FBI") != string::npos) {
    	    cout << i << " ";
    	    flag = true;
        }
    }
    if (!flag)
    	cout << "HE GOT AWAY!";
    return 0;
}