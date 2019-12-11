#include <iostream>
#include <set>
using namespace std;

#define MAX 4

set<string> result; // set을 안쓰고 전체 bool배열 하나 만들고 만들어진 숫자의 배열이 true인지 false인지 확인하면
// 중복 체크 가능 bool visit[1000000] = false; 생길때마다 true체크 이러면 시간도 줄고 금방 될듯 
// 이건 4*4여서 사용해본 거였고 숫자가 커진다면 절대 set을 사용하면 안된다. 

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int map[MAX][MAX];

void solve(int x, int y, int cnt, string num) {
	if (cnt == 7) {
		result.insert(num);
		return;
	}

	num += map[x][y] + '0';

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)continue;

		solve(nx, ny, cnt + 1, num);

	}

}

int main() {
	int T;

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		result.clear();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				solve(i, j,0,"");
			}
		}

		cout << "#" << test_case << " " << result.size() << endl;
	}

	return 0;
}