#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 1001
#define BUS_MAX 100001
#define INF 123456789

int D[MAX];
int N, M;
bool _check[MAX];

typedef struct root {
	int next = 0;
	int cost = 0;
}R;

vector<R> BUS[BUS_MAX];

priority_queue<pair<int,int>> pq;

void cal_cost(int start) {
	int min = INF;

	pq.push(make_pair(0,start));

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (D[current] < cost) {
			continue;
		}

		for (int i = 0; i < BUS[current].size(); i++) {
			int _next = BUS[current][i].next;
			int _cost = cost + BUS[current][i].cost;

			if (D[_next] > _cost) {
				D[_next] = _cost;
				pq.push(make_pair(-_cost, _next));
			}
		}
	}
}
 // min heap 또는 우선순위큐 사용
int main() {
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		R tmp;
		tmp.next = b;
		tmp.cost = c;
		BUS[a].push_back(tmp);
	}

	for (int i = 0; i < MAX; i++) {
		D[i] = INF;
	}

	int start, end;

	cin >> start >> end;

	cal_cost(start);

	cout << D[end] << endl;

	return 0;
}
