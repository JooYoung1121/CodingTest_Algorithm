#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;

	sort(routes.begin(), routes.end());

	int tmp = routes[0][1];

	for (int i = 1; i < routes.size(); i++) {
		if (tmp >= routes[i][0]) {
			tmp = min(tmp,routes[i][1]);
		}
		else {
			answer++;
			tmp = routes[i][1];
		}
	}

	return answer;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> routes;

	for (int i = 0; i < N; i++) {
		vector<int> tmp;
		int a, b;
		cin >> a >> b;
		tmp.push_back(a);
		tmp.push_back(b);

		routes.push_back(tmp);
	}

	cout << solution(routes);

	system("pause");
	return 0;
}