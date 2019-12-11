#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
using namespace std;

int cnt[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };

int main() {
	int N, M;

	cin >> N >> M;

	string A, B;

	cin >> A >> B;

	vector<int> result;

	bool chk = false;

	if (N > M)
	{
		chk = true;
		swap(N, M);
		swap(A, B);
	}

	for (int i = 0; i < N; i++) {
		if (chk) {
			result.push_back(cnt[B[i] - 65]);
			result.push_back(cnt[A[i] - 65]);
		}
		else {
			result.push_back(cnt[A[i] - 65]);
			result.push_back(cnt[B[i] - 65]);
		}
	}

	for (int i = N; i < M; i++) {
		result.push_back(cnt[B[i] - 65]);
	}

	
	while (result.size() != 2) {
		vector<int> tmp;
		
		for (int i = 0; i < result.size()-1; i++) {
			int sum = result[i] + result[i + 1];
			sum %= 10;
			tmp.push_back(sum);
		}
		result.clear();
		result = tmp;
		tmp.clear();
	}

	if (result[0] == 0)
		cout << result[1] << "%";
	else
		cout << result[0] << result[1] << "%";

	system("pause");
	return 0;
}