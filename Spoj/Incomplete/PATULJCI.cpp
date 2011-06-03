#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int N, C, M, a, b, max, maxCol;
	cin >> N >> C;
	vector <int> dwarves(N);
	vector <int> colors(C);
	
	for (int i = 0; i < N; ++i) {
		cin >> dwarves[i];
	}

	cin >> M;
	//vector <vector <int> > pretty(N,vector <int> (N,-1));
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
	//	if (pretty[a-1][b-1] == -1) {
			colors.assign(C,0);
			max = 0;
			maxCol = 0;
			for (int i = a-1; i < b; ++i) {
				colors[dwarves[i]-1]++;
				if (colors[dwarves[i]-1]>max) {
					max = colors[dwarves[i]-1];
					maxCol = dwarves[i];
				}
			}
			if (max > (b-a+1)/2.0) {
//				cout << max << " " << (b-a+1)/2.0 << endl;
				cout << "yes " << maxCol << endl;
			} else {
//				cout << max << " " << (b-a+1)/2.0 << endl;
				cout << "no" << endl;
			}
//		}
	}
	return 0;
}

