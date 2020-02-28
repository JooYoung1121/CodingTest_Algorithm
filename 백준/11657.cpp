#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 6001
#define INF 987654321

int D[502];

typedef struct graph {
	int from;
	int to;
	int cost;
}G;

G bus[MAX];

int main() {
	int N, M;
	cin >> N >> M;
	bool nega_check = false;
	int A, B, C;

	for (int i = 0; i < 502; i++) {
		D[i] = INF;
	}

	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		bus[i].from = A;
		bus[i].to = B;
		bus[i].cost = C;
	}

	D[1] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int x = bus[j].from;
			int y = bus[j].to;
			int z = bus[j].cost;
			if (D[x] != INF && D[y] > D[x] + z) {
				D[y] = D[x] + z;
				if (i == N) {
					nega_check = true;
				}
			}
		}
		
	}

	for (int i = 2; i <= N; i++) {
		if (nega_check) {
			cout << -1 << endl;
			break;
		}
		if (D[i] == INF) {
			cout << -1 << endl;
		}
		else {
			cout << D[i] << endl;
		}
	}

	return 0;
}