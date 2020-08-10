#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 51

int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };
int Map[MAX][MAX]; // 0 빈칸 1 벽 2 바이러스를 놓을 수 있는 위치 
int Time[MAX][MAX];
int N, M, Empty_Place = 0;
int Answer = 987654321;

vector<pair<int, int>> Virus;
bool Virus_Visit[MAX] = { false, }; // 놓은 바이러스 안겹치게 
bool Cont_Visit[MAX][MAX] = { false, }; // 퍼진 바이러스 위치 확인

void bfs() { // 바이러스 퍼트리기 

	queue<pair<int, int>> q;
	int result = 0;
	int Total_time = 0;

	for (int i = 0; i < Virus.size() ;i++) {
		if (Virus_Visit[i]) {
			q.push({ Virus[i].first,Virus[i].second });
			Time[Virus[i].first][Virus[i].second] = 0;
		}
	}

	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		int x = temp.first;
		int y = temp.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > N || ny <= 0 || ny > N)continue;
			if (Map[nx][ny] == 1)continue;
			if (Time[nx][ny] == -1) {
				Time[nx][ny] = Time[x][y] + 1;
				if (Map[nx][ny] == 0) {
					result++;
					Total_time = Time[nx][ny];
				}
				q.push({ nx,ny });
			}
		}
	}
	if (Empty_Place == result)
		Answer = min(Answer, Total_time);


}

void dfs(int cnt) { // M개 찾기 

	if (cnt == M) {
		memset(Time, -1, sizeof(Time));
		bfs();
		return;
	}

	int idx = 0;
	for (auto virus : Virus) {
		if (Virus_Visit[idx])continue;
		Virus_Visit[idx] = true;
		dfs(cnt + 1);
		Virus_Visit[idx] = false;
		idx++;
	}

}



int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 0) Empty_Place++;
			if (Map[i][j] == 2)
				Virus.push_back({ i,j });
		}
	}


	dfs(0);

	if (Answer == 987654321)
		cout << -1;
	else
		cout << Answer;


	system("pause");
	return 0;
}