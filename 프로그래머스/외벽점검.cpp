#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 9;

bool isWorked[15] = { false, };
bool isComplete[15] = { false, };

void dfs(int worker, vector<int>& weak, vector<int>& dist) {
	bool chk = true;

	for (int i = 0; i < weak.size(); i++) {
		if (!isComplete[i]) {
			chk = false;
			break;
		}
	}

	if (chk && worker > 0) {
		answer = min(answer, worker);
		return;
	}

	if (!chk && worker > 8)
		return;

	for (int i = 0; i < dist.size(); i++) {
		int cur = dist[i];
		if (!isWorked[i]) {
			for (int j = 0; j < weak.size(); j++) {
				if (!isComplete[j]) {
					int idx = 0;
					while (idx + j < weak.size() && weak[j] + cur >= weak[idx + j]) {
						isComplete[idx + j] = true;
						idx++;
					}
					break;
				}
			}

			isWorked[i] = true;
			dfs(worker + 1, weak, dist);
			isWorked[i] = false;

			for (int j = 0; j < weak.size(); j++) {
				isComplete[j] = false;
			}
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	sort(dist.rbegin(), dist.rend());
	for (int i = 0; i < weak.size(); i++) {
		dfs(0, weak, dist);
		int start = weak[0] + n;
		for (int j = 1; j < weak.size(); j++) {
			weak[j - 1] = weak[j];
		}
		weak[weak.size() - 1] = start;
	}
	if (answer > 8) answer = -1;
	return answer;
}

int main() {

	int n;
	vector<int> weak, dist;

	int a, b;
	cin >> n >> a >> b;

	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		weak.push_back(tmp);
	}

	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		dist.push_back(tmp);
	}

	cout << solution(n, weak, dist);

	system("pause");
	return 0;
}