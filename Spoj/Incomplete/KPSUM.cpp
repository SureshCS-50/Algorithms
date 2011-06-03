#include <iostream>
#include <vector>

using namespace std;

void sum (long long int x);

int main ()
{
    long long int N;
    vector <long long int> v;
	//long long int A[40];
    
	int i = 0;
    while (true) {
          cin >> N;
          if (N == 0) {
                break;
          }
          v.push_back(N);
    }
	int size = v.size();

    for (int i = 0; i < size; i ++) {
        sum(v[i]);
    }    
	return 0;
    
}

void sum (long long int x)
{
    long int count = 0;
	int n;    
    int temp;
	int temp1;
    bool turn = true;
	vector <int> v;
    
    for (long int i = 1; i <= x; i ++) {
        temp = i;
        //n = noofdigit(temp);
        if (i < 10) {
           if (turn) {
	          count += i;
              turn = false;
           } else {
	         count -= i;
             turn = true;
           }
        }
		int temp2 = 0;
		int n = 0;
        if (i >= 10) {
			bool turn1 = true;
			while (temp != 0) {
				n++;
				temp1 = temp%10;

				if (turn1) {
				  temp2 += temp1;
				  turn1 = false;
			   } else {
				 temp2 -= temp1;
				 turn1 = true;
			   }
                temp /= 10;
           }
			if (n%2 != 0 && turn == true) {
				count += temp2;
				turn = false;
			} else if (n%2 != 0 && turn == false) {
				count -= temp2;
				turn = true;
			} else if (n%2 == 0 && turn == false) {
				count += temp2;
				turn = false;
			} else {
				count -= temp2;
				turn = true;
			}
       }
    } 
    cout << count << endl;
}
