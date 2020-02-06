#include <iostream>
#include <string>
#include <vector>

using namespace std;


int CNT, M, N;

void Rotate(vector<vector<int>>& key) {
	vector<vector<int> > tmp(M, vector<int>(M, 0));
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			tmp[j][M - i - 1] = key[i][j];
	key = tmp;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	M = key.size();
	N = lock.size();

	bool result = true;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (lock[i][j] == 0)
				CNT++;

	for (int rotate = 0; rotate < 4; rotate++) {
		for (int i = -20; i <= 20; i++) {
			for (int j = -20; j <= 20; j++) {
				int cnt = 0;
				result = false;
				for (int x = 0; x < M; x++) {
					for (int y = 0; y < M; y++) {
						int nx = x + j;
						int ny = y + i;
						if (0 <= ny && ny < N && 0 <= nx && nx < N) {
							if (lock[ny][nx] == 1 && key[y][x] == 1) result = true;
							else if (lock[ny][nx] == 0 && key[y][x] == 1) cnt++;
						}
					}
				}
				if (cnt == CNT && !result) return true;
			}
		}
		Rotate(key);
	}


	return false;
}

int main() {

	vector<vector<int>> key, lock;

	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		vector<int> tmp;
		for (int j = 0; j < M; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		key.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		lock.push_back(tmp);
	}


	cout << solution(key, lock);
	system("pause");
	return 0;
}