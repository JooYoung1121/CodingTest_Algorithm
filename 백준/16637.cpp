#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 20
#define INF 987654321

int num[MAX];
char oper[MAX];
long long ans;
int num_cnt = 0;
int oper_cnt = 0;

long long calculate(long long i, long long j, char op) {
	switch (op) {
	case '+':
		return i + j;
	case '-':
		return i - j;
	case '*':
		return i * j;
	default:
		break;
	}
	return 0;
}

void dfs(int idx, long long result) {
	long long next_result = 0;
	long long cur_result = 0;
	if (idx >= oper_cnt) {
		if (ans < result)
			ans = result;
		return;
	}

	cur_result = calculate(result, num[idx + 1], oper[idx]);
	dfs(idx + 1, cur_result);

	if (idx + 2 < num_cnt) {
		next_result = calculate(num[idx + 1], num[idx + 2], oper[idx + 1]);
		cur_result = calculate(result, next_result, oper[idx]);
		dfs(idx + 2, cur_result);
	}
}


int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			cin >> num[num_cnt];
			num_cnt++;
		}
		else
		{
			cin >> oper[oper_cnt];
			oper_cnt++;
		}
	}

	ans = -INF;


	dfs(0, num[0]);

	cout << ans;

	system("pause");
	return 0;
}