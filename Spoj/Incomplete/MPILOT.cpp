#include <iostream>
#include <vector>
#include <algorithm>

#define lint long long

using namespace std;

struct pilot {
	lint pilotSal;
	lint assistantSal;
	lint diff;
	lint rank;
	lint index;
};

bool compare (pilot p1, pilot p2)
{
	return (p1.diff < p2.diff);
}

bool compare1 (pilot p1, pilot p2)
{
	return (p1.index< p2.index);
}
int main()
{
	lint T;
	cin >> T;
	lint temp1, temp2;
	lint sum = 0;
	vector <pilot> Pilots(T-2);

	cin >> temp1 >> temp2;
	sum += temp2;

	for (lint i = 0; i < T-2; ++i) {
		cin >> Pilots[i].pilotSal >> Pilots[i].assistantSal;
		Pilots[i].diff = Pilots[i].pilotSal - Pilots[i].assistantSal;
		Pilots[i].index = i;
	}

	if (T>1) {
		cin >> temp1 >> temp2;
		sum += temp1;
	}

	sort (Pilots.begin(), Pilots.end(), compare);
	for (lint i = 0; i < T-2; ++i) {
		Pilots[i].rank = i+1;
	}

	sort (Pilots.begin(), Pilots.end(), compare1);
	
	//cout << "Initial Sum: " << sum << endl;

	lint assistant = 1;

	for (lint i = 0; i < T-2; ++i) {
		//cout << Pilots[i].index << " " << Pilots[i].pilotSal << " " << Pilots[i].assistantSal << " " << Pilots[i].rank << " " << Pilots[i].diff << endl;
		if (assistant == 0) {
			sum += Pilots[i].assistantSal;
			assistant ++;
		} else {
			if (Pilots[i].rank > (T-2)/2) {
				sum += Pilots[i].assistantSal;
				assistant ++;
			} else {
				sum += Pilots[i].pilotSal;
				assistant --;
			}
		}
		//cout << i << ": " << sum << endl;
	}

	cout << sum;
}
