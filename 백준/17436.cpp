#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 11

int p[MAX];
long long N, M;
long long ans;

void bt(int size,int start,int l,vector<int> v) {
	if (size == l) {
		if (l % 2 == 1) {
			long long temp = 1;
			for (int i = 0; i < l; i++) {
				temp *= p[v[i]];
			}
			ans += M / temp;
		}
		else
		{
			long long temp = 1;
			for (int i = 0; i < l; i++) {
				temp *= p[v[i]];
			}
			ans -= M / temp;
		}
		return;
	}
	for (int i = start + 1; i <= N; i++) {
		v.push_back(i);
		bt(size + 1, i, l, v);
		v.pop_back();
	}
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			vector<int> v;
			v.push_back(j);
			bt(1, j, i, v);
			v.pop_back();
		}
	}
	cout << ans;

	system("pause");
	return 0;
}