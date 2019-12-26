#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());

	int sum = 1;

	for (int i = 0; i < weight.size(); i++) {
		if (sum < weight[i])break;
		sum += weight[i];
	}

	answer = sum;

	return answer;
}

int main() {

	int N;

	cin >> N;

	vector<int> weight;

	for (int i = 0; i < N; i++) {
		int a;

		cin >> a;

		weight.push_back(a);
	}

	cout << solution(weight);


	system("pause");
	return 0;
}