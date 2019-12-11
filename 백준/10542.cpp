#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAX 500001

int mafia[MAX];
bool D[MAX];
bool visit[MAX];

bool chk;
int sum;
// 그리디로 생각해서 1번이 마피아일경우 최대 경우의 수로 접근해서 최대 일 경우를 출력시키면 될듯 

int solve(int node) {
	int next;
	next = mafia[node];
	
	if (visit[node])
		return 0;

	if ((visit[next] && D[next]) || next == 0)
		return 0;

	else {
		visit[node] = true;
		if (chk) {
			chk = false;
			D[node] = true;
			sum++;
			solve(next);
		}

		else {
			chk = true;
			solve(next);
		}
	}


	return sum;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;

	cin >> N;

	
	for (int i = 1; i <= N; i++) {
		cin >> mafia[i];
	}


	int result = 0;
	
	for (int i = 1; i <= N; i++) {
		chk = true;
		sum = 0;
		memset(visit, false, sizeof(visit));
		memset(D, false, sizeof(D));
		int cnt = solve(i);	
		sum = 0;
		chk = true;
		for (int j = 1; j < i; j++) {
			sum = 0;

		}
		int tmp = solve(1);
		cnt += tmp;

		for (int j = 1; j <= N; j++) {
			if (!visit[j]) {
				int next = mafia[j];
				if (!D[next])
					cnt++;
			}
		}

		result = max(result, cnt);

	}
	cout << result;
	system("pause");
	return 0;
}