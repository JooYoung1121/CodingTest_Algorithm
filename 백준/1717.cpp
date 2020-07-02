#include <iostream>
using namespace std;

#define MAX 1000001

int Parent[MAX];

int Find(int x) {
	if (x == Parent[x]) return x;
	else return Parent[x] = Find(Parent[x]);
}

void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	Parent[x] = y;
}

int main() {

	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		Parent[i] = i;
	}

	while (m--) {
		int o, a, b;

		cin >> o >> a >> b;

		if (o == 0) {
			Merge(a, b);
		}
		else {
			if (Find(a) == Find(b))
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}


	system("pasue");
	return 0;
}