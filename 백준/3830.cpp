#include <iostream>
#include <Windows.h>
using namespace std;

#define MAX 100001

long long dist[MAX];

int p[MAX];
int s[MAX];

pair<int, long long> find(int a, long long pos) {
	if (a == p[a]) return { a, pos };
	return find(p[a], pos + dist[a]);

}

void merge(int a, int b, int w) {
	pair<int, long long> x = find(a, 0), y = find(b, 0);
	if (x.first == y.first) return;

	if (s[x.first] > s[y.first]) {
		dist[y.first] -= (y.second - x.second - w);
		p[y.first] = x.first;
		s[x.first] += s[y.first];
		s[y.first] = 1;
	}

	else {
		dist[x.first] += (y.second - x.second - w);
		p[x.first] = y.first;
		s[y.first] += s[x.first];
		s[x.first] = 1;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, M;

	while (1) {
		cin >> N;
		cin >> M;

		for (int i = 0; i < MAX; i++) {
			dist[i] = 0;
		}

		if (N == 0 && M == 0) {
			break;
		}

		for (int i = 1; i <= N; i++) {
			p[i] = i;
			s[i] = 1;
		}

		for (int j = 0; j < M; j++) {
			char oper;

			cin >> oper;

			if (oper == '!') {
				int a, b, w;
				cin >> a >> b >> w;

				merge(a, b, w);
			}

			else {
				int a, b;
				cin >> a >> b;
				pair<int, long long> x = find(a, 0);
				pair<int, long long> y = find(b, 0);

				if (x.first != y.first) {
					cout << "UNKNOWN" << "\n";
				}
				else {
					cout << -x.second + y.second << "\n";
				}

			}


		}
	}

	system("pause");

	return 0;
}