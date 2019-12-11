#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

typedef struct edge {
	int from;
	int to;
	double cost;
}E;

bool cmp(E& x, E& y) {
	return x.cost < y.cost;
}

vector<pair<double, double>> star;


double getDist(pair<double, double> pla, pair<double, double> plb) {
	return sqrt(pow(pla.first - plb.first, 2) + pow(pla.second - plb.second, 2));
}

int p[101];

int find(int x) {

	if (x == p[x])
		return x;

	return p[x] = find(p[x]);
}

void merge(int x, int y) {

	x = find(x);
	y = find(y);
	p[x] = y;

}

vector<E> adj;

int main() {
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;

		star.push_back({x,y});
	}

	for (int i = 0; i < 100; i++) {
		p[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			pair<double, double> a, b;
			a = star[i];
			b = star[j];
			E tmp;
			tmp.from = i;
			tmp.to = j;
			tmp.cost = getDist(a, b);
			adj.push_back(tmp);
		}
	}

	sort(adj.begin(), adj.end(), cmp);

	double result = 0;

	for (int i = 0; i < adj.size(); i++) {
		E e = adj[i];
		int f = find(e.from);
		int t = find(e.to);

		if (f != t) {
			merge(e.from, e.to);
			result += e.cost;
		}
	}

	printf("%0.2lf", result);

	system("pause");

	return 0;
}