#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
        int T;
        cin >> T;

        int count = 1;
        for (int i = 2; i <= T; ++i) {
                for (int j = 2; j <= sqrt((double)T); ++j) {
                        if (i%j == 0)
                                if (i/j >= j)
                                        count ++;
                                else
                                        break;
                }
                count ++;
        }
        cout << count << endl;

        return 0;
}