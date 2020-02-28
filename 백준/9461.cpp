#include <iostream>
#include <vector>
using namespace std;

int main() {
	int T;

	cin >> T;


	long long D[101];

	D[1] = 1;
	D[2] = 1;
	D[3] = 1;
	D[4] = 2;
	D[5] = 2;


	for (int i = 6; i <= 100; i++) {
		if (i % 2 == 0) {
			D[i] = D[i - 2] + D[i - 3];
		}
		else {
			D[i] = D[i - 1] + D[i - 5];
		}
	} // 그냥 D[i] = D[i-1] + D[i-5] 로 해도 됨;;

	while (T--) {
		int N;

		cin >> N;

		cout << D[N] << endl;
	}


	system("pause");
	return 0;
}