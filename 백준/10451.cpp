#include <iostream>
using namespace std;

int node[1001];
bool _check[1001];

int main() {
	int T, N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		int result = 0;
		for (int j = 0; j < N; j++) {
			cin >> node[j];
			node[j]--;
			_check[j] = false;
		}
		for (int j = 0; j < N; j++) {
			if (!_check[j]) {
				int now = j;
				_check[now] = true;

				while (1) {
					now = node[now];
					if (_check[now]) {
						result++;
						break;
					}
					else {
						_check[now] = true;

					}
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}