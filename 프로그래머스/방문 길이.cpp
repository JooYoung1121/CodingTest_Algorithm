#include <string>
#include <iostream>
using namespace std;

int dx[4] = {-1,0,1,0}; // up right down left
int dy[4] = {0,1,0,-1};
bool visit[11][11][11][11] = {false,};

int solution(string dirs)
{
	int answer = 0;

	int x = 5;
	int y = 5;

	for (int i = 0; i < dirs.size(); i++) {
		int nx, ny;
		if (dirs[i] == 'U') {
			nx = x + dx[0];
			ny = y + dy[0];
		}
		else if (dirs[i] == 'R') {
			nx = x + dx[1];
			ny = y + dy[1];
		}
		else if (dirs[i] == 'D') {
			nx = x + dx[2];
			ny = y + dy[2];
		}
		else {
			nx = x + dx[3];
			ny = y + dy[3];
		}

		if (nx < 0 || nx > 10 || ny < 0 || ny > 10)continue;

		if (!visit[x][y][nx][ny])
		{
			answer++;
			visit[x][y][nx][ny] = true;
			visit[nx][ny][x][y] = true;
		}
		x = nx;
		y = ny;
	}

	return answer;
}

int main() {
	string dirs;

	cin >> dirs;

	cout << solution(dirs);

	system("pause");
	return 0;
}