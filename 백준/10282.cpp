#include <iostream>
#include <vector>
#include <Windows.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 10001
#define INF 987654321

vector<pair<int,int>> com[MAX];
int D[MAX];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n, d, c;

		cin >> n >> d >> c;

		for (int i = 1; i <= n; i++) {
			D[i] = INF;
			com[i].clear();
		}

		while (d--) {
			int a, b, s;

			cin >> a >> b >> s;

			com[b].push_back({ a,s }); // to, second
		}

		D[c] = 0;

		priority_queue<pair<int, int>> pq;

		pq.push({ c,0 }); // to,second
		
		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();

			int cur = p.first;
			int time = -p.second;

			for (int i = 0; i < com[cur].size(); i++) {
				int next = com[cur][i].first;
				int add = com[cur][i].second;

				if (D[next] > D[cur] + add) {
					D[next] = D[cur] + add;
					pq.push({ next,-(time + add) });
				}
			}
		}
		int cnt = 0,result = 0;


		for (int i = 1; i <= n; i++) {
			if (D[i] != INF)
			{
				cnt++;
				result = max(result, D[i]);
			}
		}

		cout << cnt << " " << result << "\n";
	}


	system("pause");
	return 0;
}