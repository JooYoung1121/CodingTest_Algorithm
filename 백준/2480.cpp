#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	int _max;

	if (a < b) {
		if (b < c) {
			_max = c;
		}
		else
			_max = b;
	}
	else {
		if (a > c)
			_max = a;
		else
			_max = c;
	}
	int result;
	if (a == b) {
		if (b == c) {
			result = 10000 + (a * 1000);
		}
		else {
			result = 1000 + (a * 100);
		}
	}
	else {
		if (b == c) {
			result = 1000 + (b * 100);
		}
		else if (a == c) {
			result = 1000 + (a * 100);
		}
		else {
			result = _max * 100;
		}
	}

	cout << result;
	system("pause");
	return 0;
}