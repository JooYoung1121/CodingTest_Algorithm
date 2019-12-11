#include <iostream>
#include <Windows.h>
using namespace std;

int C[10];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;

	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> C[i];
		}
		int cnt = 0;
		while (1) {
			bool chk = true;

			for (int i = 0; i < N; i++) {
				if (C[i] % 2 == 1) {
					C[i]++;
				}
			}
			for (int i = 0; i < N; i++) {
				if (i == N - 1) {
					if (C[i] != C[0]) {
						chk = false;
						break;
					}
				}
				else {
					if (C[i] != C[i + 1]) {
						chk = false;
						break;
					}
				}
			}
			if (chk)
				break;

			int tmp[10];
			for (int i = 0; i < N; i++) {
				if (i == N - 1) {
					tmp[0] = C[i] / 2;
					C[i] /= 2;
				}
				else {
					tmp[i + 1] = C[i] / 2;
					C[i] /= 2;
				}
			}

			for (int i = 0; i < N; i++) {
				C[i] += tmp[i];
			}

			cnt++;

		}

		cout << cnt << endl;
	}


	system("pause");
	return 0;
}