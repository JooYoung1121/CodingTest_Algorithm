#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<int> people, int limit) {
	int answer = 0;

	sort(people.begin(), people.end());
	
	int start = 0;
	
	for (int i = people.size() - 1; i > start; i--) {
		if (people[i] + people[start] <= limit) {
			start++;
			answer++;
		}
		else
			answer++;
	}

	return answer;
}


int main() {

	int N;
	cin >> N;

	vector<int> people;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		people.push_back(p);
	}

	int limit;
	cin >> limit;

	cout << solution(people,limit);

	system("pause");
	return 0;
}