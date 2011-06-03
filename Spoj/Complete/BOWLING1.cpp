#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
	int T;
	cin >> T;
	string scores;
	int num;
	vector <int> sc;
	bool flag = true;
	int flag10, flag9, score, sz;
	float count;
	getline(cin,scores);
	for (int i = 0; i < T; ++i) {
		getline(cin,scores);
		num = 0;
		for (int j = 0; j < scores.length(); ++j) {
			if (scores[j] == '\r') {scores.erase(scores.begin()+j);--j;}
		}
		for (int j = 0; j < scores.length(); ++j) {
			while(j<scores.length() && scores[j]==' ') {
				++j;
				if (flag)
					sc.push_back(num);
				num = 0;
				flag = false;
			}
			num = num*10 + scores[j]-'0';
			flag = true;
		}
		if (flag) sc.push_back(num);
		flag10 = flag9 = score = count = 0;
		sz = sc.size();
		for (int j = 0; j < sz;) {
			if (count >= 9) {
				if (sc[j] == 10) {
					score += 10;
					if (j+1<sz) score+=sc[j+1];
					if (j+2<sz) score+=sc[j+2];
					count ++;
				} else {
					if (j<sz-1 && sc[j] + sc[j+1] == 10) {
						score += 10;
						j += 2;
						if (j<sz) score += sc[j];
						count ++;
					} else {
						score += sc[j];
						++j;
						if (j<sz) score += sc[j];
						count += 1;
					}
				}
				break;
			}
			
			if (sc[j] == 10) {
				score += 10;
				if (j+1<sz) score+=sc[j+1];
				if (j+2<sz) score+=sc[j+2];
				++j;
				count ++;
			} else {
				if (j<sz-1 && sc[j] + sc[j+1] == 10) {
					score += 10;
					j += 2;
					if (j<sz) score += sc[j];
					count ++;
				} else {
					score += sc[j];
					++j;
					if (j<sz) score += sc[j];
					++j;
					count += 1;
				}
			}
		}
		cout << score << endl;
		sc.clear();
                scores.clear();
	}
	return 0;
}
