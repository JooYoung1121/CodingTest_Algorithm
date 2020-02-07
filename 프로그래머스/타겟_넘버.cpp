#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;

int Target;

bool visit[21] = { false, };

void dfs(int result,int idx,vector<int>& numbers) {
	if (idx == numbers.size()) {
		if (result == Target) answer++;
		return;
	}
	dfs(result + numbers[idx], idx + 1, numbers);
	dfs(result - numbers[idx], idx + 1, numbers);
}


int solution(vector<int> numbers, int target) {
	Target = target;

	dfs(0, 0, numbers);

	return answer;
}

int main() {
	int N;
	vector<int> numbers;
	int target;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	cin >> target;

	cout << solution(numbers, target);

	system("pause");
	return 0;
}