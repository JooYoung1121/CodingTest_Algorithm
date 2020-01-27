#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int one[5] = {1,2,3,4,5};
int two[8] = {2,1,2,3,2,4,2,5};
int three[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	int _max1 = 0;
	int _max2 = 0;
	int _max3 = 0;

	int idx1 = 0, idx2 = 0, idx3 = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (idx1 % 5 == 0)
			idx1 = 0;
		if (idx2 % 8 == 0)
			idx2 = 0;
		if (idx3 % 10 == 0)
			idx3 = 0;

		if (one[idx1] == answers[i])
			_max1++;
		if (two[idx2] == answers[i])
			_max2++;
		if (three[idx3] == answers[i])
			_max3++;

		idx1++;
		idx2++;
		idx3++;
	}

	priority_queue<p, vector<p>, less<p>> pq;

	pq.push({_max1,1});
	pq.push({ _max2,2 });
	pq.push({_max3,3});

	int _max;
	_max = pq.top().first;

	while (!pq.empty()) {
		p tmp = pq.top();
		pq.pop();
		if (_max == tmp.first)
			answer.push_back(tmp.second);
	}


	sort(answer.begin(), answer.end());
	return answer;
}

int main() {

	vector<int> answers;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		answers.push_back(a);
	}

	vector<int> result = solution(answers);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	system("pause");
	return 0;
}