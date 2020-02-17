#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define MAX 101
typedef pair<int, int> p;

int dx[6] = {-1,0,1,0,0,0}; // up right down left high down
int dy[6] = {0,1,0,-1,0,0};
int dh[6] = {0,0,0,0,1,-1};

int M, N, H;

int WareHouse[MAX][MAX][MAX]; // 가로 세로 높이
int answer = 0;

queue<pair<p,int>> q; // 그냥 구조체 하나 만들어서 x,y,h로 가도 됨

bool Check_Tomato() {
	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (WareHouse[x][y][h] == 0) return false;
			}
		}
	}
	return true;
}


int main() {

	cin >> M >> N >> H;

	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> WareHouse[x][y][h];
				if (WareHouse[x][y][h] == 1) q.push({ {x,y},h });
			}
		}
	}


	while (!q.empty()) {
		int Size = q.size();

		while(Size--){
			int x = q.front().first.first;
			int y = q.front().first.second;
			int h = q.front().second;

			q.pop();

			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nh = h + dh[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || nh < 0 || nh >= H)continue;

				if (WareHouse[nx][ny][nh] == 0) {
					WareHouse[nx][ny][nh] = 1;
					q.push({ {nx,ny},nh });
				}
			}
		}
		if (q.size() == 0 && Check_Tomato())
			break;
		else if (q.size() == 0 && !Check_Tomato()) {
			answer = -1;
			break;
		}
		answer++;
	}

	cout << answer;


	system("pause");

	return 0;
}