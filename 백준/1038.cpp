#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

long long N;
queue<long long> q;
long long D[1000001];
int idx = 9;

void Solve() {
	while (idx <= N)
	{
		if (q.empty())
			return;
		//큐에 있는 감소수를 꺼내서
		long long descendingNum = q.front();
		q.pop();
		//마지막 자리 숫자를 확인
		int lastNum = descendingNum % 10;
		//마지막 자리 숫자보다 작은 숫자들을 붙여 나감
		for (int i = 0; i < lastNum; i++)
		{
			q.push(descendingNum * 10 + i);
			D[++idx] = descendingNum * 10 + i;
		}
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		q.push(i);
		D[i] = i;
	}

	Solve();

	if (D[N] == 0 && N != 0)
		cout << -1;
	else
		cout << D[N];


	system("pause");
	return 0;
}