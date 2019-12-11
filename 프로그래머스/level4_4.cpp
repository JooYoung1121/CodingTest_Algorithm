#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <algorithm>
using namespace std;


int D[101][100001];// i번째 도시를 지날 때 j시간 이내에 모인 최대금액

int solve(vector<vector<int>>& travel,int K,int cnt) {
	if (K < 0) return -10000000;

	int &ret = D[cnt][K];

	if (travel.size() == cnt) return 0;

	if (ret != -1) return ret;

	ret = max(solve(travel, K - travel[cnt][0], cnt + 1) + travel[cnt][1],
		solve(travel, K - travel[cnt][2], cnt + 1) + travel[cnt][3]);

	return ret;

}


int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	
	memset(D, -1, sizeof(D));


	answer = solve(travel, K, 0);

	return answer;
}

int main() {
	int N, K;

	cin >> N >> K;
	vector<vector<int>> travel;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < 4; j++) {
			int tmp;
			cin >> tmp;
			temp.push_back(tmp);
		}
		travel.push_back(temp);
	}

	cout << solution(K, travel);

	system("pause");
	return 0;
}