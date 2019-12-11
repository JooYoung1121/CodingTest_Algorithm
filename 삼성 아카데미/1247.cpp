#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10

pair<int,int> arr[MAX];
int N;
pair<int, int> home, com;
bool visit[10] = {false,};
int answer;

int dist(pair<int,int> a, pair<int,int> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(int cnt,int idx,int sum) {
	if (cnt == N) {
		sum += dist(com, arr[idx]);
		answer = min(answer, sum);
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			solve(cnt + 1, i, sum + dist(arr[i], arr[idx]));
			visit[i] = false;
		}
	}
}


int main() {
	int T;

	cin >> T;

	for (int j = 1; j <= T; j++) {
		
		cin >> N;

		int x, y;
		cin >> x >> y;
		com = { x,y };
		cin >> x >> y;
		home = { x,y };

		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			arr[i] = { x,y };
		}
		answer = 987654321;



		for (int i = 0; i < N; i++){
			visit[i] = true;
			solve(1, i, dist(home, arr[i]));
			visit[i] = false;
		}
		cout << "#" << j << " " << answer << endl;

	}



	return 0;
}