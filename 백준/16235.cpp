#include <iostream>
#include <deque>
using namespace std;

//vector 나 pq를 사용하니 시간초과가 뜨는거로 봐서는 sorting이 들어가면 안될 꺼 같다. 
// 어처피 나이는 1씩 증가이기 때문에 앞 뒤만 확인해도 될 듯 싶다. 

int A[11][11];
long long map[11][11];

deque<int> tree[11][11];

int dead[11][11];

int N;
int xx[8] = { -1,0,1,-1,1,-1,0,1 };
int yy[8] = { -1,-1,-1,0,0,1,1,1 };

void spring() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			deque<int> temp;
			for (int m = 0; m < tree[i][j].size(); m++) {
				int age = tree[i][j][m];
				if (map[i][j] >= age) {
					map[i][j] -= age;
					age++;
					temp.push_back(age);
				}
				else {
					dead[i][j] += age/2;
				}
			}
			tree[i][j] = temp;
		}
	}
}

void summer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += dead[i][j];
			dead[i][j] = 0;
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int m = 0; m < tree[i][j].size(); m++) {
				int mod = tree[i][j][m] % 5;
				if (mod == 0) {
					int x1, y1;
					for (int z = 0; z < 8; z++) {
						x1 = i + xx[z];
						y1 = j + yy[z];
						if (x1 > 0 && x1 <= N && y1 > 0 && y1 <= N) {
							tree[x1][y1].push_front(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] += A[i][j];
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M, K;

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			map[i][j] = 5;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		int x, y, age;

		cin >> x >> y >> age;

		tree[x][y].push_front(age);
	}

	for (int i = 0; i < K; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	int result = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result += tree[i][j].size();
		}
	}
	cout << result;

	return 0;
}