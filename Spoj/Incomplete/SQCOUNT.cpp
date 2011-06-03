#include <iostream>
#include <vector>

using namespace std;

struct coordinate {
	int x1, y1, x2, y2;
};

int noOfSquares (vector <coordinate> v);

int main()
{
	struct coordinate c;
	vector <coordinate> v;
	vector <int> ans;

	int T;

	while (true) {
		cin >> T;
		if (T == 0) {
			break;
		}
		for (int i = 0; i < T; ++i) {
			cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
			v.push_back(c);
		}
		ans.push_back(noOfSquares(v));
		v.clear();
	}

	for (int i = 0; i < (int)ans.size(); i ++) {
		cout << ans[i] << endl;
	}

	

	return 0;
}

int noOfSquares (vector <coordinate> v)
{
	int h;
	int w;
	int one = 0;
	int two = 0;
	int three = 0;
	int sum = 0;

	for (int i = 0; i < (int)v.size(); ++i) {		
		w = (v[i].x1 > v[i].x2) ? (v[i].x1-v[i].x2) : (v[i].x2-v[i].x1);
		h = (v[i].y1 > v[i].y2) ? (v[i].y1-v[i].y2) : (v[i].y2-v[i].y1);
		
		one += w*h;
			
		if (w >= 2 || h >=2) {
			two += (w-1)*(h-1);
		}		

		if (w >= 3 || h >= 3) {
			three += (w-2)*(h-2);
		}
		//cout << one << " " << two << " " << three  << endl;
	}

	for (int i = 0; i < (int)v.size()-1; ++i) {
		for (int j = i+1; j < (int)v.size(); ++j) {
			if ( (v[j].x1 == v[i].x2) || (v[j].x2 == v[i].x1) || (v[j].x1 == v[i].x1) || (v[j].x2 == v[i].x2) ) {
				if((v[j].y1 >= v[i].y1 || v[j].y1 >= v[i].y2) && (v[i].y2 >= v[j].y2 || v[i].y1 >= v[j].y2)) {
					int m = abs( abs	(v[j].y1-v[j].y2) - abs(v[i].y1-v[i].y2) );
					if (m >= 2) {
						two += m-1;
					}
					if (m >= 3) { 
						three += (m-2)*2;
					}
				}

				if((v[i].y1 >= v[j].y1 || v[i].y1 >= v[j].y2) && (v[j].y2 >= v[i].y2 || v[j].y1 >= v[i].y2)) {					
					int m = abs( abs(v[i].y1-v[i].y2) - abs(v[j].y1-v[j].y2) );
					if (m >= 2) {
						two += m-1;
					}
					if (m >= 3) { 
						three += (m-2)*2;
					}
				}
			}
			if ( (v[j].y1 == v[i].y2) || (v[j].y1 == v[i].y1) || (v[j].y2 == v[i].y1) || (v[j].y2 == v[i].y2) ) {
				if((v[j].x1 > v[i].x1 || v[j].y1 > v[i].x2) && (v[i].x2 > v[j].x2 || v[i].x1 > v[j].x2)) {
					int m = abs( (v[j].x1-v[j].x2) - abs(v[i].x1-v[i].x2) );
					if (m >= 2) {
						two += m-1;
					}
					if (m >= 3) { 
						three += (m-2)*2;
					}
				}
				if((v[i].x1 > v[j].x1 || v[i].x1 > v[j].x2) && (v[j].x2 > v[i].x2 || v[j].x1 > v[i].x2)) {
					int m = abs( (v[i].x1-v[i].x2) - abs(v[j].x1-v[j].x2) );
					if (m >= 2) {
						two += m-1;
					}
					if (m >= 3) { 
						three += (m-2)*2;
					}
				}
			}						
		}
	}
	sum = one + two + three;
	return sum;
}									

