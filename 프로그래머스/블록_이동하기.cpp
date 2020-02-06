#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

struct info {
	p robot[2]; // x,y
	int dir[2];
};

int N;
int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
bool visit[101][101][4] = { false, };

bool chk(p a, p b, vector<vector<int>>& board) {
	if (a.first < 0 || a.first >= N || a.second < 0 || a.second >= N || b.first < 0 || b.first >= N || b.second < 0 || b.second >= N || board[a.first][a.second] == 1 || board[b.first][b.second] == 1)
		return true;
	return false;
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	N = board.size();
	queue<info> q;

	visit[0][0][1] = visit[0][1][3] = true;
	p a, b;
	a = { 0,0 };
	b = { 0,1 };
	q.push({ a,b,1,3 });
	while (!q.empty()) {
		int Size = q.size();
		while (Size--) {
			info tmp = q.front();
			q.pop();
			if ((tmp.robot[0].first == N - 1 && tmp.robot[0].second == N - 1) || (tmp.robot[1].first == N - 1 && tmp.robot[1].second == N - 1)) return answer;

			for (int i = 0; i < 4; i++) {
				p NextPos[2];
				NextPos[0] = { tmp.robot[0].first + dx[i],tmp.robot[0].second + dy[i] };
				NextPos[1] = { tmp.robot[1].first + dx[i],tmp.robot[1].second + dy[i] };
				int dir[2];
				dir[0] = tmp.dir[0];
				dir[1] = tmp.dir[1];

				if (chk(NextPos[0], NextPos[1], board) || visit[NextPos[0].first][NextPos[0].second][dir[0]] || visit[NextPos[1].first][NextPos[1].second][dir[1]])continue;
				visit[NextPos[0].first][NextPos[0].second][dir[0]] = visit[NextPos[1].first][NextPos[1].second][dir[1]] = true;
				q.push({ NextPos[0],NextPos[1],dir[0],dir[1] });
			}

			for (int i = -1; i <= 1; i++) {
				if (i == 0)continue;
				for (int j = 0; j < 2; j++) {
					int x = tmp.robot[j].first;
					int y = tmp.robot[j].second;
					int dir = (tmp.dir[j] + i + 4) % 4;
					int prev = (dir - i + 4) % 4;
					int oppo = (dir + 2) % 4;

					p NextPos[2];
					NextPos[0] = { x + dx[dir], y + dy[dir] };
					NextPos[1] = { x + dx[dir] + dx[prev], y + dy[dir] + dy[prev] };

					if (chk(NextPos[0], NextPos[1], board) || visit[x][y][dir] || visit[NextPos[0].first][NextPos[0].second][oppo]) continue;
					visit[x][y][dir] = visit[NextPos[0].first][NextPos[0].second][oppo] = true;
					p save = { x,y };
					q.push({ save,NextPos[0],dir,oppo });
				}
			}
		}
		answer++;
	}

	return answer;
}

int main() {
	vector<vector<int>> board;

	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		board.push_back(tmp);
	}

	cout << solution(board);

	system("pause");
	return 0;
}