#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	long long X, Y;

	cin >> X >> Y;

	long long dif = Y - X;

	int result = 0;

	if (dif < 1)
		result = 0;
	else {
		int cnt = 1;

		while (cnt * cnt < dif) {
			cnt++;
		}

		if (cnt * cnt - cnt < dif)
			result = cnt * 2 - 1;
		else
			result = cnt * 2 - 2;
	}

	cout << result;

	system("pause");
	return 0;
}