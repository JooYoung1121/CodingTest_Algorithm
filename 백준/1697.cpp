#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

bool visit[100001] = {false,};

int main() {
	int N, K;

	cin >> N >> K;

	queue<p> q;

	q.push({ N,0 });

	while (!q.empty()) {
		p tmp = q.front();
		q.pop();

		visit[tmp.first] = true;

		if (tmp.first == K) {
			cout << tmp.second;
			break;
		}
		if (tmp.first != 0 && !visit[tmp.first-1])
			q.push({tmp.first-1,tmp.second+1});
		if (tmp.first != 100000 && !visit[tmp.first+1])
			q.push({ tmp.first + 1,tmp.second + 1 });
		if (tmp.first * 2 <= 100000 && !visit[tmp.first*2])
			q.push({tmp.first * 2, tmp.second+1});

	}

	return 0;
}