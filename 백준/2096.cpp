#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;

#define MAX 100001

int map[MAX][3];

int min_D[3];
int max_D[3];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> map[i][0] >> map[i][1] >> map[i][2];
	}

	min_D[0] = max_D[0] = map[1][0];
	min_D[1] = max_D[1] = map[1][1];
	min_D[2] = max_D[2] = map[1][2];

	for (int i = 2; i <= N; i++) {
		int temp1, temp2, temp3;

		temp1 = map[i][0] + max(max_D[0], max_D[1]);
		temp2 = map[i][1] + max(max(max_D[0], max_D[1]), max_D[2]);
		temp3 = map[i][2] + max(max_D[1], max_D[2]);

		max_D[0] = temp1;
		max_D[1] = temp2;
		max_D[2] = temp3;

		temp1 = map[i][0] + min(min_D[0], min_D[1]);
		temp2 = map[i][1] + min(min(min_D[0], min_D[1]), min_D[2]);
		temp3 = map[i][2] + min(min_D[1], min_D[2]);

		min_D[0] = temp1;
		min_D[1] = temp2;
		min_D[2] = temp3;
	}

	int _max = 0;
	int _min = 987654321;

	_max = max(max(max_D[0], max_D[1]), max_D[2]);
	_min = min(min(min_D[0], min_D[1]), min_D[2]);

	cout << _max << " " << _min;

	system("pause");

	return 0;
}