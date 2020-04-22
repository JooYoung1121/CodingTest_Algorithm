#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 21
#define INF 987654321


int map[MAX][MAX]; // 나눌 선거구 
int Person[MAX][MAX]; // 인구수
pair<int, int> Pos[4]; // 꼭지점 위 오 왼 아
int N, Answer = INF;

int Cal(int Num) {
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == Num) {
				result += Person[i][j];
			}
		}
	}
	return result;
}

bool Chk(int x,int y,int d1,int d2) {
	if (x + d1 + d2 > N || x > x + d1 + d2) return false;
	if (y - d1 > y || y - d1 < 1) return false;
	if (y > y + d2) return false;
	if (y + d2 > N)return false;

	return true;
}


void Labeling(int x,int y,int d1,int d2) {

	// Pos[0] up Pos[1] Right Pos[2] Left Pos[3] Down

	// 1
	int cnt = 0;
	for (int i = 1; i < Pos[2].first; i++) {
		if (i >= Pos[0].first) cnt++;
		for (int j = 1; j <= Pos[0].second - cnt; j++) {
			map[i][j] = 1;
		}
	}

	// 2
	cnt = 1;
	for (int i = 1; i <= Pos[1].first; i++) {
		if (i > Pos[0].first) cnt++;
		for (int j = Pos[0].second + cnt; j <= N; j++) {
			map[i][j] = 2;
		}
	}

	//3
	cnt = 0;

	for (int i = N; i >= Pos[2].first; i--) {
		if (i < Pos[3].first) cnt++;
		for (int j = 1; j < Pos[3].second - cnt; j++) {
			map[i][j] = 3;
		}
	}

	//4
	cnt = 0;
	for (int i = N; i > Pos[1].first; i--) {
		if (i <= Pos[3].first) cnt++;
		for (int j = Pos[3].second+cnt; j <= N; j++) {
			map[i][j] = 4;
		}
	}
}

void solve(int x, int y) { // 기준점 x, y
	
	vector<int> Vote; // 인구수, 선거구
	
	for (int d1 = 1; d1 <= y; d1++) { // d1 d2 길이
		for (int d2 = 1; d2 < N; d2++) {
			
			if (Chk(x, y, d1, d2)) {
				Pos[0].first = x;
				Pos[0].second = y;
				Pos[1].first = x + d2;
				Pos[1].second = y + d2;
				Pos[2].first = x + d1;
				Pos[2].second = y - d2;
				Pos[3].first = x + d1 + d2;
				Pos[3].second = y - d1 + d2;
				Vote.clear();
				for (int i = 1; i <= N; i++) {
					for (int j = 1; j <= N; j++) {
						map[i][j] = 5;
					}
				}

				Labeling(x, y, d1, d2);

				for (int i = 1; i <= 5; i++) {
					Vote.push_back(Cal(i));
				}

				sort(Vote.begin(), Vote.end());

				Answer = min(Answer, Vote[4] - Vote[0]);
			}
		}
	}

}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Person[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			solve(i, j);
		}
	}

	cout << Answer;

	system("pause");
	return 0;
}