#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	if (a + b > b + a)
		return true;
	else
		return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> arr;

	for (int i = 0; i < numbers.size(); i++) {
		arr.push_back(to_string(numbers[i]));
	}

	sort(arr.begin(), arr.end(),cmp);

	for (int i = 0; i < arr.size(); i++) {
		answer += arr[i];
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}

int main() {
	int N;
	cin >> N;

	vector<int> numbers;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		numbers.push_back(a);
	}

	cout << solution(numbers);


	system("pause");
	return 0;
}