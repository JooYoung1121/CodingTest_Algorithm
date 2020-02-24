#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 2001
#define INF 200000000 // 이 값을 987654321로하면 틀리게 되고 200000000으로 하면 맞는다 이유는 모르겠다.. 

typedef pair<int, int> p;

int main() {

	int T;

	cin >> T;

	while (T--) {
		vector<int> answer;
		vector<p> road[MAX];
		int n, m, t;
		cin >> n >> m >> t;

		int s, g, h;
		cin >> s >> g >> h;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			c *= 2;
			if ((a == g && b == h) || (a == h && b == g)) c -= 1;
			road[a].push_back({ b, c });
			road[b].push_back({ a, c });
		}

		vector<int> Destination;

		for (int i = 0; i < t; i++) {
			int x;
			cin >> x;
			Destination.push_back(x);
		}

		int Dist[2001];

		for (int i = 1; i <= 2000; i++) {
			Dist[i] = INF;
		}

		priority_queue<p, vector<p>, greater<p>> pq;
		Dist[s] = 0;
		pq.push({ Dist[s],s });

		while (!pq.empty()) {
			int Cost = pq.top().first;
			int Node = pq.top().second;
			pq.pop();
			for (int i = 0; i < road[Node].size(); i++) {
				int Next = road[Node][i].first;
				int NextCost = road[Node][i].second;

				if (Cost + NextCost < Dist[Next]) {
					Dist[Next] = Cost + NextCost;
					pq.push({ Dist[Next],Next });
				}
			}
		}
		sort(Destination.begin(), Destination.end());

		for (int i : Destination) {
			if (Dist[i] % 2 != 0)
				cout << i << ' ';
		}
		cout << endl;
	}

	system("pause");
	return 0;
}