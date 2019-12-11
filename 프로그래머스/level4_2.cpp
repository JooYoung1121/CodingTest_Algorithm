#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 1000001

int D[MAX][2];

int _max = 0;

int solution(vector<int> money) {
	int answer = 0;
	memset(D, 0, sizeof(D));

	if (money.size() == 3)
		answer = max(money[0], max(money[1], money[2]));
	else {

		//0번째를 털었을때
		D[0][0] = money[0];
		D[1][0] = D[0][0];
		D[2][0] = D[0][0] + money[2];

		//0번째를 안털었을때
		D[0][1] = 0;
		D[1][1] = money[1];
		D[2][1] = money[2];

		for (int i = 3; i < money.size(); i++) {
			if (i == money.size() - 1) {
				D[i][1] = max(max(D[i - 2][1] + money[i], D[i - 3][1] + money[i]), D[i - 1][1]);
			} 
			else{
				D[i][0] = max(max(D[i - 2][0] + money[i], D[i - 3][0] + money[i]), D[i - 1][0]);
				D[i][1] = max(max(D[i - 2][1] + money[i], D[i - 3][1] + money[i]), D[i - 1][1]);
			}
		}

		answer = max(D[money.size() - 1][1], D[money.size() - 2][0]);
	}
	return answer;
}

int main() {

	int N;

	cin >> N;

	vector<int> money;

	for (int i = 0; i < N; i++) {
		int m;
		cin >> m;
		money.push_back(m);
	}

	cout << solution(money);

	system("pause");
	return 0;
}