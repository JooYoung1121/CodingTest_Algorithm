#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Info {
	int x, y, dir;
};

int N, K;

int map[13][13]; // 0 : Èò»ö 1 : »¡°£»ö 2 : ÆÄ¶õ»ö 
vector<int> Map_state[13][13]; // ÁÂÇ¥ À§ ¸» »óÅÂ 
int dx[4] = {0,0,-1,1}; // right left up down
int dy[4] = {1,-1,0,0};
Info info[11];


int Reverse_Dir(int Num) {
	int dir = info[Num].dir;
	if (dir == 0) return 1;
	if (dir == 1) return 0;
	if (dir == 2) return 3;
	if (dir == 3) return 2;
}

int Find_Position(int x,int y,int idx) {
	int result = 0;
	for (int Num : Map_state[x][y])
	{
		if (Num == idx) return result;
		result++;
	}
}

bool Check_Finish() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Map_state[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}


void Move_Chess(int x, int y, int nx, int ny, int chess_num, int order, int color) {

	int size = Map_state[x][y].size();
	if (color == 0) {
		for (int i = order; i < size; i++) {
			int Idx = Map_state[x][y][i];
			Map_state[nx][ny].push_back(Idx);
			info[Idx].x = nx;
			info[Idx].y = ny;
		}
		for (int i = 0; i < size - order; i++) {
			Map_state[x][y].pop_back();
		}
	}
	else if (color == 1) {
		for (int i = size-1; i >= order; i--) {
			int Idx = Map_state[x][y][i];
			Map_state[nx][ny].push_back(Idx);
			info[Idx].x = nx;
			info[Idx].y = ny;
		}
		for (int i = 0; i < size - order; i++) {
			Map_state[x][y].pop_back();
		}
	}
	else if (color == 2) {
		int dir = Reverse_Dir(chess_num);
		info[chess_num].dir = dir;
		int nnx = x + dx[dir];
		int nny = y + dy[dir];
		if (nnx > 0 && nnx <= N && nny > 0 && nny <= N) {
			if (map[nnx][nny] != 2) Move_Chess(x, y, nnx, nny, chess_num, order, map[nnx][nny]);
		}
	}
}

void solve() {
	bool Flag = false;
	int time = 0;

	while (1) {
		if (time > 1000)break;

		for (int i = 0; i < K; i++) {
			int x = info[i].x;
			int y = info[i].y;
			int dir = info[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int Pos = Find_Position(x, y, i);

			if (nx > 0 && nx <= N && ny > 0 && ny <= N) Move_Chess(x,y,nx,ny,i,Pos, map[nx][ny]);
			else Move_Chess(x,y,nx,ny,i,Pos, 2);

			if (Check_Finish()) {
				Flag = true;
				break;
			}
			
		}

		if (Flag) break;
		time++;
	}

	if (Flag) cout << time+1;
	else cout << -1;
}


int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		Info tmp;
		cin >> tmp.x >> tmp.y >> tmp.dir;
		tmp.dir--;
		info[i] = tmp;
		Map_state[tmp.x][tmp.y].push_back(i);
	}

	solve();


	system("pause");
	return 0;
}