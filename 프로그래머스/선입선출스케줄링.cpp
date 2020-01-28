#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001

// parametric search 방식 검색해서 알아보기 


int solution(int n, vector<int> cores) {
	
	int Size = cores.size();
	int mincore = MAX;
	int maxcore = 0;
	int mintime = 0;
	int maxtime = 0;
	int midtime = 0;

	if (n <= Size) return n;

	for (int i = 0; i < cores.size(); i++) {
		mincore = min(mincore, cores[i]);
		maxcore = max(maxcore, cores[i]);
	}

	mintime = (mincore * (n - Size)) / Size;
	maxtime = (maxcore * (n - Size)) / Size;

	while (mintime <= maxtime) {
		int work = Size;
		int cur = 0;

		midtime = (mintime + maxtime) / 2; // 중간시간을 현재 시점으로

		for (int i = 0; i < cores.size(); i++) {
			work += (midtime / cores[i]); // 현재 코어의 작업량
			if ((midtime % cores[i]) == 0) cur++; // 현재 막 작업을 할당받은 코어의 개수
		}

		if (n > work) mintime = midtime + 1;
		else if (n <= (work - cur)) maxtime = midtime - 1;
		else {
			int tmp = work - cur;
			for (int i = 0; i < Size; i++) {
				if ((midtime % cores[i]) == 0)tmp++;

				if (tmp == n) return i + 1;
			}
		}
	}

	return 0;
}

int main() {

	int n;

	vector<int> cores;

	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		cores.push_back(a);
	}

	cout << solution(n, cores);

	system("pause");
	return 0;
}