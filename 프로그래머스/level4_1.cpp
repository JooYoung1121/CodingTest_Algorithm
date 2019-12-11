#include <iostream>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;

#define MAX 2001
int dp[MAX][MAX];

int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	
	int sizel, sizer;
	sizel = left.size();
	sizer = right.size();

	//vector<vector<int>> dp(sizel + 1, vector<int>(sizer + 1, 0));
	


	for (int i = 0; i <= sizer; i++) {
		dp[0][i] = -1;
	}

	for (int i = 1; i <= sizel; i++) {
		for (int j = 1; j <= sizer; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (dp[i][j - 1] != -1 && left[i - 1] > right[j - 1]) {
				dp[i][j] = dp[i][j - 1] + right[j - 1];
			}
		}
	}

	answer = dp[sizel][sizer];
	

	return answer;
}


int main() {
	int N;

	cin >> N;

	vector<int> left;
	vector<int> right;

	for (int i = 0; i < N / 2; i++) {
		int l;
		cin >> l;
		left.push_back(l);

	}
	for (int i = 0; i < N / 2; i++) {
		int r;
		cin >> r;
		right.push_back(r);
	}

	int result;
	result = solution(left, right);

	cout << result;

	system("pause");
	return 0;
}