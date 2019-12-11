#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

int pig[MAX];
vector<int> custom[101]; // 첫번째 값은 가지고 있는 열쇠 갯수 그 다음부턴 어떤 열쇠인지 마지막은 살 돼지 마리수

// 네트워크 플로우 개념을 이해하고 풀어보자 

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int M, N;

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		cin >> pig[i];
	}
	
	for (int i = 1; i <= N; i++) {
		int a;

		cin >> a;

		custom[i].push_back(a);
		for (int j = 0; j < a; j++) {
			int k;
			cin >> k;
			custom[i].push_back(k);
		}

		int b;

		cin >> b;

		custom[i].push_back(b);
	}





	return 0;

}