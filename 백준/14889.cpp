#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int status[21][21];
bool Chk[21] = {false,};
int Answer = 987654321;

void Solve(int Cnt, int Idx) {
	if (Idx == N+1)return;
	if (Cnt == N / 2) {
		int Start_Score = 0, Link_Score = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (Chk[i] && Chk[j]) Start_Score += status[i][j];
				if (!Chk[i] && !Chk[j]) Link_Score += status[i][j];
			}
		}

		Answer = min(Answer, abs(Start_Score - Link_Score));
		return;
	}

	Chk[Idx] = true;
	Solve(Cnt + 1, Idx + 1);
	Chk[Idx] = false;
	Solve(Cnt, Idx + 1);
}

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> status[i][j];
		}
	}
	Solve(0, 1);
	
	cout << Answer;

	system("pause");
	return 0;
}