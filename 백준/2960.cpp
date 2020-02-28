#include <iostream>
using namespace std;

#define MAX 1001

int main() {
	int N, K;
	cin >> N >> K;
	bool _check[MAX] = { false, };

	int count = 0;
	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			if (!_check[j])
				count++;
			_check[j] = true;
			if (count == K) {
				cout << j << endl;
				return 0;
			}
		}
	}

	return 0;
}