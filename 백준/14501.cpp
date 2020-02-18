#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 16

pair<int, int> Consulting[MAX];// Days, Cost

// dp 로 풀 경우 dp[N] -> N일까지 얻는 이익
// dp[i] = max(Consulting[i] + dp[j],dp[i]) // N일을 기준으로 N일 이전에 얻을 수 있는 경우 모두 비교 

/*
	for(int i=2;i<=N;i++){
		for(int j=1;j<i;j++){
			if(i - j >= Consulting[j].first)
				dp[i] = max(Consulting[i].second + dp[j],dp[i]);
		}
	}

*/

int Answer = 0;

int N;

void solve(int Cost, int Idx) { // 완전탐색

	bool chk = true;

	for (int i = Idx; i <= N; i++) {
		int Next = i + Consulting[i].first;

		if (Next > N + 1)continue;
		
		chk = false;
		solve(Cost + Consulting[i].second, Next);
	}

	if (chk) // 현재 기준으로 더이상 일을 할 수 없을 경우 마지막 플래그 
		Answer = max(Answer, Cost);
}

int main() {

	cin >> N;


	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		Consulting[i] = { a,b };
	}
	
	for (int i = 1; i <= N; i++) { // day
		int Next = i + Consulting[i].first;

		if (Next > N + 1) continue;

		solve(Consulting[i].second, Next);

	}

	cout << Answer;

	system("pause");
	return 0;
}