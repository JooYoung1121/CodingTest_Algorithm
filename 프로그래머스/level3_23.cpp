#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define MAX 105

int col[MAX][MAX][MAX][MAX]; // x,y 에서 x,y+1까지
int paper[MAX][MAX][MAX][MAX]; // x,y 에서 x+1,y까지

struct info {
	int x, y, a;
};

struct cmp {
	bool operator()(info a, info b) {
		if (a.x == b.x) {
			if (a.y == b.y) {
				return a.a > b.a;
			}
			return a.y > b.y;
		}
		else {
			return a.x > b.x;
		}
	}
};

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < build_frame.size(); i++) {
		int x, y, a, b;
		x = build_frame[i][0];
		y = build_frame[i][1];
		a = build_frame[i][2];
		b = build_frame[i][3];
		x++;

		if (b == 0) { // 삭제
			if (a == 0) { // 기둥
				bool flag = true;

				if (col[x][y + 1][x][y + 2] == 1 && paper[x - 1][y + 1][x][y + 1] != 1 && paper[x][y + 1][x + 1][y + 1] != 1)flag = false;
				if (paper[x][y + 1][x + 1][y + 1] == 1) {
					if (paper[x - 1][y + 1][x][y + 1] == 1 && paper[x + 1][y + 1][x + 2][y + 1] == 1);
					else if (col[x + 1][y][x + 1][y + 1] == 1);
					else flag = false;
				}
				if (paper[x - 1][y + 1][x][y + 1] == 1) {
					if (x - 2 >= 0 && paper[x - 2][y + 1][x - 1][y + 1] == 1 && paper[x][y + 1][x + 1][y + 1] == 1);
					else if (col[x - 1][y][x - 1][y + 1] == 1);
					else flag = false;
				}

				if (flag) col[x][y][x][y + 1] = 0;
			}
			else { // 보
				bool flag = true;
				if (col[x][y][x][y + 1] == 1) {
					if (paper[x - 1][y][x][y] == 1);
					else if (col[x][y-1][x][y] == 1);
					else flag = false;
				}
				if (col[x + 1][y][x + 1][y + 1] == 1) {
					if (paper[x + 1][y][x + 2][y] == 1);
					else if (col[x + 1][y - 1][x + 1][y]);
					else flag = false;
				}
				if (paper[x - 1][y][x][y] == 1) {
					if (col[x - 1][y - 1][x - 1][y] == 1 || col[x][y - 1][x][y] == 1);
					else flag = false;
				}
				if (paper[x + 1][y][x + 2][y] == 1) {
					if (col[x + 1][y - 1][x + 1][y] == 1 || col[x + 2][y - 1][x + 2][y] == 1);
					else flag = false;
				}

				if (flag) paper[x][y][x + 1][y] = 0;
			}
		}
		else { // 설치
			if (a == 0) { // 기둥
				if (y == 0 || paper[x - 1][y][x][y] == 1 || paper[x][y][x + 1][y] == 1 || col[x][y - 1][x][y] == 1) {
					col[x][y][x][y + 1] = 1;
				}
				else
					continue;
			}
			else { // 보
				if (col[x][y - 1][x][y] == 1 || col[x + 1][y - 1][x + 1][y] == 1 || (paper[x - 1][y][x][y] == 1 && paper[x + 1][y][x + 2][y] == 1))
					paper[x][y][x + 1][y] = 1;
				else
					continue;
			}
		}
	}

	priority_queue<info, vector<info>, cmp> pq;

	for (int i = 1; i < 105; i++) {
		for (int j = 0; j < 105; j++) {
			info tmp;

			if (col[i][j][i][j + 1] == 1) {
				tmp.x = i-1;
				tmp.y = j;
				tmp.a = 0;
				pq.push(tmp);
			}

			if (paper[i][j][i + 1][j] == 1)
			{
				tmp.x = i-1;
				tmp.y = j;
				tmp.a = 1;
				pq.push(tmp);
			}

		}
	}

	while (!pq.empty()) {
		info tmp = pq.top();
		pq.pop();

		vector<int> ttmp;

		ttmp.push_back(tmp.x);
		ttmp.push_back(tmp.y);
		ttmp.push_back(tmp.a);

		answer.push_back(ttmp);
	}

	return answer;
}

int main() {

	int N, M;
	cin >> N >> M;

	vector<vector<int>> build_frame;

	for (int i = 0; i < M; i++) {
		vector<int> tmp;
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		build_frame.push_back(tmp);
	}

	vector<vector<int>> result = solution(N, build_frame);

	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < 3; j++) {
			cout << result[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}