#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int N;

	cin >> N;

	int result = 0;

	int num[10] = { 0 };

	if (N == 0)
		num[0]++;

	while (N) {
		int a = N % 10;

		if (a == 9)
			a = 6;

		num[a]++;

		N /= 10;
	}
	num[6]++;
	num[6] /= 2;

	for (int i = 0; i < 10; i++) {
		if (num[i] > num[result])
			result = i;
	}

	cout << num[result];
	system("pause");
	return 0;
}