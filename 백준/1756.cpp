#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 300001

int oven[MAX];
int pizza[MAX];
int chk[MAX];

int main() {
	int D, N;

	cin >> D >> N;

	chk[0] = 1000000001;
	for (int i = 1; i <= D; i++) {
		cin >> oven[i];
		chk[i] = min(oven[i], chk[i - 1]);
	}

	for (int i = 1; i <= N; i++) {
		cin >> pizza[i];
	}

	int idx = 1;
	for (int i = D; i > 0; i--) {
		if (pizza[idx] > chk[i]) continue;
		idx++;
		if (idx > N) {
			cout << i;
			system("pause");
			return 0;
		}
	}
	cout << 0;
	system("pause");
	return 0;
}