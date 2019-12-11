#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 10001

char ox[MAX];

int main() {

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> ox[i];
	}

	int bonus = 0;

	int result = 0;
	for (int i = 1; i <= N; i++) {
		if (ox[i] == 'O') {
			result += i + bonus;
			bonus++;
		}
		else {
			bonus = 0;
		}
	}
	cout << result;

	system("pause");
	return 0;
}