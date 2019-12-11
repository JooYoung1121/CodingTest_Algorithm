#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int solution(vector<int> A, vector<int> B) { // A는 고정 B만 순서 조정 
	int answer = 0;

	priority_queue<int,vector<int>,greater<int>> pA, pB;

	for (int i = 0; i < A.size(); i++) {
		pA.push(A[i]);
		pB.push(B[i]);
	}

	while(!pA.empty() && !pB.empty()) {
		if (pA.top() < pB.top()) {
			pA.pop();
			answer++;
		}
		pB.pop();
	}
	return answer;
}

int main() {
	vector<int> A, B;

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}

	cout << solution(A, B);


	system("pause");
	return 0;
}