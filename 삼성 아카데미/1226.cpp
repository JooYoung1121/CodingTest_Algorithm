#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 16

int map[MAX][MAX];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
pair<int, int> start,fin;

bool visit[MAX][MAX];

bool chk = false;

void solve(pair<int, int> start) {

	int x = start.first;
	int y = start.second;

	if (start == fin) {
		chk = true;
		return;
	}
	
	visit[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny] || nx < 0 || nx >= 16 || ny < 0 || ny >= 16) continue;

		if (map[nx][ny] == 1)continue;

		solve({ nx,ny });

	}

}

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
		cin >> N;
		chk = false;
		for (int i = 0; i < MAX; i++) {
			string a;
			cin >> a;
			for (int j = 0; j < MAX; j++) {
				visit[i][j] = false;
				map[i][j] = a[j] - '0';
				if (map[i][j] == 2)
					start = { i,j };
				else if (map[i][j] == 3)
					fin = { i,j };
			}
		}

		solve(start);

		if (chk)
			cout << "#" << N << " " << 1 << endl;
		else
			cout << "#" << N << " " << 0 << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}