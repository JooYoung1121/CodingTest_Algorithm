#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int dx[9] = {0,-1,-1,0,1,1,1,0,-1};
int dy[9] = {0,0,-1,-1,-1,0,1,1,1};

struct info {
	int number;
	int dir;
};

int Result = 0;

info See[4][4];
p Fish[17];

void Fish_Print() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << See[i][j].number << ' ' << See[i][j].dir << "      ";
		}
		cout << endl;
	}
	cout << endl;
}

void Fish_Move() {
	for (int i = 1; i < 17; i++) { // i번째 물고기 이동 
		if (Fish[i].first == -1) continue;
		int x = Fish[i].first;
		int y = Fish[i].second;
		int dir = See[x][y].dir;
		int nx;
		int ny;

		int cnt = 0;

		bool chk = true;

		while (1) {
			if (cnt == 8) {
				chk = false;
				break;
			}
			nx = x + dx[dir];
			ny = y + dy[dir];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || See[nx][ny].number == -1) {// 경계 벗어날때 또는 상어
				if (dir == 8) dir = 1;
				else dir++;
			}
			else
				break;

			cnt++;
		}
		if (!chk) continue;

		int number = See[nx][ny].number;

		info tmp = See[nx][ny];
		See[nx][ny] = See[x][y];
		See[x][y] = tmp;

		See[nx][ny].dir = dir; // 45도 방향 움직여주기 

		if (number == 0) { // 빈 공간이라면 
			Fish[i] = { nx,ny };
		}
		else {
			p ttmp = Fish[number]; // 물고기 정보 변경
			Fish[number] = Fish[i];
			Fish[i] = ttmp;
		}
	}
}

void Solve(p Shark,int Sum) {
	
	info See_Temp[4][4];
	p Fish_Temp[17];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			See_Temp[i][j] = See[i][j];
		}
	}

	for (int i = 1; i < 17; i++) {
		Fish_Temp[i] = Fish[i];
	}

	Fish_Move();

	Result = max(Result, Sum);

	p idx = Shark;
	int x = idx.first;
	int y = idx.second;

	int dir = See[x][y].dir;

	for(int i=0;i<3;i++) { // 상어가 이동할 수 있는 가능성이 있는지 확인 
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) break;
		if (See[nx][ny].number > 0) {// 물고기가 있을 경우만 
			
			int number = See[nx][ny].number;
			int ddir = See[nx][ny].dir;
			
			See[nx][ny].number = -1;
			See[idx.first][idx.second] = { 0,0 };
			Fish[number] = { -1,-1 };
			p shark_idx = { nx,ny };

			Solve(shark_idx, Sum + number);

			See[nx][ny] = { number,ddir };
			Fish[number] = { nx,ny };
		}
		x = nx;
		y = ny;
	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			See[i][j] = See_Temp[i][j];
		}
	}

	for (int i = 1; i < 17; i++) {
		Fish[i] = Fish_Temp[i];
	}
	
}

int main() {
	p Shark = { 0,0 };

	for (int i = 0; i < 4; i++) {
		vector<info> tmp;
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			See[i][j] = { a,b };
			Fish[a] = { i,j }; // 물고기가 가지는 좌표 만약 없어졌다면 -1,-1로 이동시키기 
		}
	}

	Result += See[0][0].number;
	int Dir = See[0][0].dir;
	See[0][0] = { -1,Dir };
	Fish[Result] = { -1,-1 };
	
	Solve(Shark,Result);
	
	cout << Result;

	system("pause");
	return 0;
}