#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int answer = 0;

bool cmp(char a, char b) {
	return a > b;
}

int solution(string numbers) {
	
	string tmp = numbers;
	sort(numbers.begin(), numbers.end(),cmp);

	vector<bool> Prime(stoi(numbers) + 1);

	for (int i = 0; i < Prime.size(); i++) {
		Prime[i] = false;
	}
	Prime[0] = true;
	Prime[1] = true;
	for (int i = 2; i < Prime.size(); i++) {
		for (int j = i+i; j < Prime.size(); j += i) {
			Prime[j] = true;
		}
	}
	
	set<int> primes;

	sort(tmp.begin(), tmp.end());

	do {
		for (int i = 1; i <= tmp.size(); i++) {
			int prime = stoi(tmp.substr(0, i));
			if (!Prime[prime])
				primes.insert(prime);
		}


	} while (next_permutation(tmp.begin(), tmp.end()));

	answer = primes.size();
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string numbers;
	cin >> numbers;

	cout << solution(numbers);

	system("pause");
	return 0;
}