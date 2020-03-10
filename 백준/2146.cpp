#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 987654321

int N;
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
bool Map[MAX][MAX];
int NewMap[MAX][MAX];
bool visit[MAX][MAX] = {false,};

void dfs(int x,int y,int Num) {
	visit[x][y] = true;
	NewMap[x][y] = Num;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx <= 0 || nx > N || ny <= 0 || ny > N || visit[nx][ny])continue;
		if(Map[nx][ny])
			dfs(nx, ny, Num);
	}
}

int bfs(int Num) {
	queue<pair<int, int>> q;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (NewMap[i][j] == Num)
			{
				visit[i][j] = true;
				q.push({ i,j });
			}
		}
	}
	int result = 0;

	while (!q.empty()) {
		int Size = q.size();
		for (int i = 0; i < Size; i++) {
			pair<int, int> tmp = q.front();
			int x = tmp.first;
			int y = tmp.second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx <= 0 || nx > N || ny <= 0 || ny > N)continue;

				if (Map[nx][ny] && NewMap[nx][ny] != Num) return result; // ´Ù¸¥ ¼¶ µµÂø(¹Ù´Ù°¡ ¾Æ´Ò °æ¿ì)
				
				if (!Map[nx][ny] && !visit[nx][ny]) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		result++;
	}


}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Map[i][j];
		}
	}

	int Num = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && Map[i][j])
				dfs(i, j, Num++);
		}
	}

	int result = INF;

	for (int i = 1; i < Num; i++) {
		memset(visit, false, sizeof(visit));
		result = min(result, bfs(i));
	}

	cout << result;

	system("pause");
	return 0;
}