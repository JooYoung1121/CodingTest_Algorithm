#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> ans;

	for (int i = 0; i < heights.size(); i++)
	{
		int top = 0;
		int cur = heights[i];
		for (int j = 0; j < i; j++) {
			if (cur < heights[j])
				top = max(top, j+1);
		}
		ans.push_back(top);
	}


	return ans;
}

int main() {

	int N;

	cin >> N;

	vector<int> heights;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;

		heights.push_back(a);
	}

	vector<int> ans = solution(heights);

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	system("pause");
	return 0;
}