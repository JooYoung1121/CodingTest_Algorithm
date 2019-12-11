#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

int main() {
	int e, f, c;

	cin >> e >> f >> c;

	int result = 0;

	int N;

	N = e + f; // 가지고있는 빈병과 새병의 갯수 합

	while (N >= c) {
		result += N / c;
		N = (N / c) + (N % c);
	}

	cout << result;



	system("pause");
	return 0;
}