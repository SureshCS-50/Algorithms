    #include <iostream>
    #include <cstdio>

    #define lint long long

    using namespace std;

    lint absolute (lint a);

    int main()
    {
       lint T, i;
       cin >> T;

       lint a, b, c, j, k;
       unsigned lint A,B, C;
       for (i = 0; i < T; ++i) {
	       scanf("%lld", &a);
	       scanf("%lld", &b);
	       scanf("%lld", &c);
          //cin >> a >> b >> c;
          A = absolute(a);
          if (b == absolute(b)) {
             B = absolute(b);
             C = A*A-2ULL*B;
          } else {
             B = absolute(b);
             C = A*A+2ULL*B;
          }
          cout << C << endl;
       }

       return 0;
    }

    lint absolute (lint a)
    {
       if (a < 0) return -a;
       return a;
    }