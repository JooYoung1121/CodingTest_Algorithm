#include <iostream>
using namespace std;

char map[8][8];

int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int N;
		cin >> N;
		int ans = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> map[i][j];
			}
		}
		bool flag;
		for (int i = 0; i < 8; i++) { // 고정값 
			for (int n = 0; n <= 8 - N; n++) { // 길이
				flag = true;
				for (int j = 0; j < N / 2; j++) { // 왼쪽값 판별 N길이는 고정
					if (map[i][j + n] != map[i][N + n - 1 - j]) {
						flag = false;
						break;
					}
				}
				if (flag)
					ans++;
			}
		}
		for (int i = 0; i < 8; i++) { // 고정값 
			for (int n = 0; n <= 8 - N; n++) {
				flag = true;
				for (int j = 0; j < N / 2; j++) {
					if (map[j + n][i] != map[N + n - 1 - j][i]) {
						flag = false;
						break;
					}
				}
				if (flag)
					ans++;
			}
		}
		cout << "#" << test_case << " " << ans << endl;
	}
	return 0;
}