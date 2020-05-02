#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define MAX 101

int Answer = 0;
int R, C, K;

int Max_Col = 0, Max_Row = 0;

int Map[MAX][MAX];

int main() {

	cin >> R >> C >> K;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> Map[i][j];
		}
	}

	Max_Col = 3;
	Max_Row = 3;

	while (1) {
		if (Map[R][C] == K) break;

		if (Answer > 100) {
			Answer = -1;
			break;
		}

		if (Max_Row >= Max_Col) {
			vector<pair<int,int>> Count;
			int Max_Col_tmp = 0;
			for (int i = 1; i <= Max_Row; i++) {
				map<int, int> Count_map;
				Count.clear();
				for (int j = 1; j <= Max_Col; j++) {
					if (Map[i][j] == 0)continue;
					Count_map[Map[i][j]]++;
				}

				map<int, int>::iterator iter;
				for (iter = Count_map.begin(); iter != Count_map.end(); iter++) {
					Count.push_back({ iter->second,iter->first });
				}
				sort(Count.begin(), Count.end());

				for (int j = 1; j <= Max_Col; j++) {
					Map[i][j] = 0;
				}

				int Idx = 1;
				for (int j = 0; j < Count.size(); j++) {
					Map[i][Idx++] = Count[j].second;
					Map[i][Idx++] = Count[j].first;
				}

				Idx--;
				Max_Col_tmp = max(Max_Col_tmp, Idx);
			}
			Max_Col = Max_Col_tmp;
		}
		else {
			vector<pair<int, int>> Count;
			int Max_Row_tmp = 0;
			for (int i = 1; i <= Max_Col; i++) {
				map<int, int> Count_map;
				Count.clear();
				for (int j = 1; j <= Max_Row; j++) {
					if (Map[j][i] == 0)continue;
					Count_map[Map[j][i]]++;
				}
				map<int, int>::iterator iter;
				for (iter = Count_map.begin(); iter != Count_map.end(); iter++) {
					Count.push_back({ iter->second,iter->first });
				}
				sort(Count.begin(), Count.end());

				for (int j = 1; j <= Max_Row; j++) {
					Map[j][i] = 0;
				}

				int Idx = 1;
				for (int j = 0; j < Count.size(); j++) {
					Map[Idx++][i] = Count[j].second;
					Map[Idx++][i] = Count[j].first;
				}

				Idx--;
				Max_Row_tmp = max(Max_Row_tmp, Idx);
			}
			Max_Row = Max_Row_tmp;
		}
		Answer++;
	}

	cout << Answer;

	system("pause");
	return 0;
}