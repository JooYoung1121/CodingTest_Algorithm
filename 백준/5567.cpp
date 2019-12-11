#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

#define MAX 501

int visit[MAX];
vector<int> dongi[MAX];

void find(int a) {
	
	int next;

	for (int i = 0; i < dongi[a].size(); i++) {
		next = dongi[a][i];
		visit[next] = 1;
	}

	if (a == 1) // 친구의 친구를 찾아가기 
	{
		for (int i = 0; i < dongi[a].size(); i++) {
			next = dongi[a][i];
			find(next);
		}
	}

}

int main() {
	int N,M;

	cin >> N >> M;

	int a, b;
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		dongi[a].push_back(b);
		dongi[b].push_back(a);
	}

	find(1);

	for (int i = 2; i <= N; i++) {
		if (visit[i] == 1)
			cnt++;
	}

	cout << cnt;

	system("pause");
	return 0;
}