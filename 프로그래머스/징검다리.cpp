#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int distance, vector<int> rocks, int n) {
	int answer = 1;

	sort(rocks.begin(), rocks.end());

	int start = 1;
	int end = distance;

	while (start <= end) {
		int mid = (start + end) / 2;

		int cnt = 0;
		int last = 0;
		int gap;
		for (int i = 0; i <= rocks.size(); i++) {
			if (i == rocks.size()) {
				gap = distance - rocks[i-1];
			}
			else {
				gap = rocks[i] - last;
			}

			if (gap < mid)
				cnt++;
			else if(i != rocks.size())
				last = rocks[i];
		}
		if (cnt > n)
			end = mid - 1;
		else
		{
			answer = mid;
			start = mid + 1;
		}
	}

	return answer;
}

int main() {

	int distance, n, M;
	vector<int> rocks;

	cin >> distance >> n >> M; 

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		rocks.push_back(a);
	}

	cout << solution(distance, rocks, n);


	system("pause");
	return 0;
}