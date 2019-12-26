#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	int map1[17][17];
	int map2[17][17];

	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 17; j++) {
			map1[i][j] = 0;
			map2[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		vector<int> tmp1, tmp2;
		int num = arr1[i];
		int num2 = arr2[i];
		while (num != 0) {
			tmp1.push_back(num % 2);
			num /= 2;
		}

		while (num2 != 0) {
			tmp2.push_back(num2 % 2);
			num2 /= 2;
		}

		reverse(tmp1.begin(), tmp1.end());
		reverse(tmp2.begin(), tmp2.end());

		int cnt = n - 1;
		for (int j = tmp1.size() - 1; j >= 0; j--) {
			map1[i][cnt] = tmp1[j];
			cnt--;
		}
		cnt = n - 1;
		for (int j = tmp2.size() - 1; j >= 0; j--) {
			map2[i][cnt] = tmp2[j];
			cnt--;
		}
	}


	for (int i = 0; i < n; i++) {
		string tmp = "";
		for (int j = 0; j < n; j++) {
			if (map1[i][j] != 0 || map2[i][j] != 0)
				tmp += '#';
			else
				tmp += " ";
		}
		answer.push_back(tmp);
	}

	return answer;
}

int main() {
	int N;

	cin >> N;

	vector<int> arr1, arr2;
	vector<string> result;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr1.push_back(a);
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr2.push_back(a);
	}

	result = solution(N,arr1, arr2);

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}

	system("pause");
	return 0;
}