#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

#define MAX 101

char map[MAX][MAX];
int result[MAX][MAX];

int N;
string dir;


int main() {

	cin >> N;
	cin >> dir;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = '.';
			result[i][j] = 0;
		}
	}

	int x = 1;
	int y = 1;

	for (int i = 0; i < dir.length(); i++) {
		int nx = x;
		int ny = y;
		if (dir[i] == 'D') {
			nx++;
		}
		else if (dir[i] == 'R') {
			ny++;
		}
		else if (dir[i] == 'L') {
			ny--;
		}
		else {
			nx--;
		}

		if (nx < 1 || nx > N || ny < 1 || ny > N) {
			nx = x;
			ny = y;
			continue;
		}

		if (dir[i] == 'R' || dir[i] == 'L')
		{
			result[x][y] |= 1;
			result[nx][ny] |= 1;
		}
		else {
			result[x][y] |= 2;
			result[nx][ny] |= 2;
		}

		x = nx;
		y = ny;
	}



	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (result[i][j] == 0)
				cout << '.';
			else if (result[i][j] == 1)
				cout << '-';
			else if (result[i][j] == 2)
				cout << '|';
			else
				cout << '+';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}