#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 4001

int D[MAX][MAX];

int main() {
	string a, b;

	getline(cin, a);
	getline(cin, b);

	int answer = 0;
	
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			D[i][j] = 0;
		}
	}

	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				D[i + 1][j + 1] = D[i][j] + 1;
				answer = max(answer, D[i + 1][j + 1]);
			}
		}
	}

	cout << answer;

	system("pause");
	return 0;
}