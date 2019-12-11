#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 101

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool exist[26] = { false, };
pair<int, int> p1[26], p2[26];

bool visit[MAX][MAX] = {false};
vector<string> map;
int M, N;

bool solve(int dir,pair<int,int> start,pair<int,int> end,int cnt) {
	bool result = false;

	if (cnt > 1)return false;

	if (start == end) return true;

	visit[start.first][start.second] = true;

	for (int i = 0; i < 4; i++) {
		int nx = start.first + dx[i];
		int ny = start.second + dy[i];

		

		if (nx < 0 || nx >= M || ny < 0 || ny >= N)continue;
		if (visit[nx][ny])continue;


		if (map[nx][ny] == '.' || map[nx][ny] == map[end.first][end.second]) {
			if (dir == 5) {
				if (solve(i, { nx,ny }, end,cnt))
					result = true;
			}
			else {
				int tmp;
				tmp = (dir + 1 + 4) % 4;
				tmp = (tmp + 1 + 4) % 4;
				if (dir != i) {
					if (i == tmp) {
						if (solve(i, { nx,ny }, end, cnt))
							result = true;
					}
					else {
						if (solve(i, { nx,ny }, end, cnt+1))
							result = true;
					}
				}
				else {
					if (solve(i, { nx,ny }, end, cnt))
						result = true;
				}
			}
			
		}

		visit[nx][ny] = false;

	}

	return result;
}

string solution(int m, int n, vector<string> board) {
	string answer = "";

	map = board;


	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		p1[i] = p2[i] = { -1,-1 };
		exist[i] = false;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ('A' <= board[i][j] && board[i][j] <= 'Z') {
				int idx = board[i][j] - 'A';
				if (p1[idx].first == -1) p1[idx] = { i, j }, cnt++;
				else p2[idx] = { i, j };
				exist[idx] = 1;
			}
		}
	}

	while (cnt) {
		bool chk = false;
		
		for (int i = 0; i < 26; i++) {
			if (!exist[i])continue;
			
			memset(visit, false, sizeof(visit));

			if (solve(5,p1[i], p2[i],0)) {
				map[p1[i].first][p1[i].second] = '.';
				map[p2[i].first][p2[i].second] = '.';
				chk = true;
				exist[i] = false;
				answer += (char)(i + 'A');
				break;
			}
		}
		if (!chk)
		{
			return "IMPOSSIBLE";
		}
		cnt--;
	}

	return answer;
}


int main() {

	while (1) {
		cin >> M >> N;

		vector<string> board;

		for (int i = 0; i < M; i++) {
			string tmp;
			cin >> tmp;
			board.push_back(tmp);
		}

		cout << solution(M, N, board);

	}
	system("pause");
	return 0;
}