#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	int T;

	cin >> T;

	while (T--) {
		int a, b;

		cin >> a >> b;

		int result = 0;

		if (a == 1) {
			result += 5000000;
		}
		else if (a >= 2 && a <= 3) {
			result += 3000000;
		}
		else if (a >= 4 && a <= 6) {
			result += 2000000;
		}
		else if (a >= 7 && a <= 10) {
			result += 500000;
		}
		else if (a >= 11 && a <= 15) {
			result += 300000;
		}
		else if (a >= 16 && a <= 21) {
			result += 100000;
		}

		if (b == 1) {
			result += 5120000;
		}
		else if (b >= 2 && b <= 3) {
			result += 2560000;
		}
		else if (b >= 4 && b <= 7) {
			result += 1280000;
		}
		else if (b >= 8 && b <= 15) {
			result += 640000;
		}
		else if (b >= 16 && b <= 31) {
			result += 320000;
		}

		cout << result << endl;

		
	}


	system("pause");
	return 0;
}