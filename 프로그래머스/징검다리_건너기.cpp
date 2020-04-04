#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_Possible(int mid,vector<int>& stones,int k) {
	int cur = -1; // À§Ä¡
	for (int i = 0; i < stones.size(); i++) {
		if (stones[i] - mid >= 0) {
			if (i - cur > k)return false;
			cur = i;
		}
	}
	if (stones.size() - cur > k)return false;
	return true;
}

int solution(vector<int> stones, int k) {
	int answer = 0;
	int left = *min_element(stones.begin(), stones.end());
	int right = *max_element(stones.begin(), stones.end());
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (is_Possible(mid, stones, k)) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else right = mid - 1;
	}
	
	return answer;
}

int main() {

	vector<int> stones;
	int k;

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		stones.push_back(a);
	}

	cin >> k;

	cout << solution(stones, k);

	system("pause");
	return 0;
}