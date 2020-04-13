#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 21

int N, result = 0;

int map[MAX][MAX];
int tmp[MAX][MAX];


void merge(int d) {
	queue<int> q;

	if (d == 0) { // up
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[j][i] != 0) q.push(map[j][i]); // 나오는 숫자 순서대로 queue에 넣기 
				map[j][i] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int tmp = q.front();
				q.pop();

				if (map[idx][i] == 0) map[idx][i] = tmp; // 비어있다면 
				else if (map[idx][i] == tmp) {
					map[idx++][i] *= 2;
				}
				else map[++idx][i] = tmp;
			}
		}
	}
	else if (d == 1) { // down
		for (int i = 0; i < N; i++) {
			for (int j = N-1; j >= 0; j--) {
				if (map[j][i] != 0) q.push(map[j][i]); // 나오는 숫자 순서대로 queue에 넣기 
				map[j][i] = 0;
			}

			int idx = N-1;

			while (!q.empty()) {
				int tmp = q.front();
				q.pop();

				if (map[idx][i] == 0) map[idx][i] = tmp; // 비어있다면 
				else if (map[idx][i] == tmp) {
					map[idx--][i] *= 2;
				}
				else map[--idx][i] = tmp;
			}
		}
	}
	else if (d == 2) { // left
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != 0) q.push(map[i][j]); // 나오는 숫자 순서대로 queue에 넣기 
				map[i][j] = 0;
			}

			int idx = 0;

			while (!q.empty()) {
				int tmp = q.front();
				q.pop();

				if (map[i][idx] == 0) map[i][idx] = tmp; // 비어있다면 
				else if (map[i][idx] == tmp) {
					map[i][idx++] *= 2;
				}
				else map[i][idx++] = tmp;
			}
		}


	}
	else { // right
		for (int i = 0; i < N; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (map[i][j] != 0) q.push(map[i][j]); // 나오는 숫자 순서대로 queue에 넣기 
				map[i][j] = 0;
			}

			int idx = N - 1;

			while (!q.empty()) {
				int tmp = q.front();
				q.pop();

				if (map[i][idx] == 0) map[i][idx] = tmp; // 비어있다면 
				else if (map[i][idx] == tmp) {
					map[i][idx--] *= 2;
				}
				else map[i][idx--] = tmp;
			}
		}
	}
}

void solve(int cnt) {

	if (cnt == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				result = max(result, map[i][j]);
			}
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = map[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		merge(i);
		solve(cnt + 1);
		for (int j = 0; j < N; j++) {
			for (int m = 0; m < N; m++) {
				map[j][m] = tmp[j][m];
			}
		}
	}

}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}


	solve(0);
	cout << result;

	system("pause");
	return 0;
}