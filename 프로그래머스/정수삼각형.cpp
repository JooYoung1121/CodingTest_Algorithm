#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 501

int D[MAX][MAX];

int solution(vector<vector<int>> triangle) {
	int answer = 0;

	int size = triangle.size();

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			D[i + 1][j + 1] = triangle[i][j];
		}
	}

	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)
				D[i][j] += D[i-1][j];
			else {
				D[i][j] += max(D[i-1][j-1],D[i-1][j]);
			}
		}
	}

	answer = D[1][1];
	for (int i = 1; i <= size; i++) {
		answer = max(answer, D[size][i]);
	}

	return answer;
}

int main() {
	int N;

	cin >> N;

	vector<vector<int>> triangle;

	for (int i = 1; i <= N; i++) {
		vector<int> tmp;
		for (int j = 1; j <= i; j++) {
			int a;
			cin >> a;
			tmp.push_back(a);
		}
		triangle.push_back(tmp);
	}

	cout << solution(triangle);
	system("pause");
	return 0;
}