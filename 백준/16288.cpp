#include <iostream>
#include <Windows.h>
#include <queue>
using namespace std;

int cus[100];

int main() {
	int N, K;
	cin >> N >> K;
	queue<int> pass[100];

	for (int i = 0; i < N; i++) {
		cin >> cus[i];
	}

	for (int i = 0; i < N; i++) {
		bool chk = false;

		for (int j = 0; j < K; j++) {

			if (pass[j].empty())
			{
				chk = true;
				pass[j].push(cus[i]);
				break;
			}

			if (cus[i] > pass[j].back())
			{
				chk = true;
				pass[j].push(cus[i]);
				break;
			}
		}
		if (!chk)
		{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	system("pause");
	return 0;
}