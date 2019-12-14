#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end(),greater<int>());


	for (int i = 0; i < citations.size(); i++) {
		if (citations[i] <= answer)break;
		answer++;
	}

	return answer;
}

int main() {
	vector<int> citations;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		citations.push_back(a);
	}
	cout << solution(citations);


	system("pause");
	return 0;
}