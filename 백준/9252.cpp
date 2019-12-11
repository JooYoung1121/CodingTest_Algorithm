#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
using namespace std;

#define MAX 1001

int D[MAX][MAX];

vector<int> LCS;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string A, B;

	getline(cin, A);
	getline(cin, B);

	A = '0' + A;
	B = '0' + B;

	for (int i = 0; i < A.length(); i++) {
		for (int j = 0; j < B.length(); j++) {
			if (i == 0 || j == 0) {
				D[i][j] == 0;
				continue;
			}
			if (A[i] == B[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else {
				if (D[i - 1][j] > D[i][j - 1]) {
					D[i][j] = D[i - 1][j];
				}
				else {
					D[i][j] = D[i][j - 1];
				}
			}
		}
	}

	cout << D[A.length() - 1][B.length() - 1] << "\n";

	int i = A.length() - 1;
	int j = B.length() - 1;

	while (D[i][j] != 0) {
		if (D[i][j] == D[i][j - 1]) {
			j--;
		}
		else if (D[i][j] == D[i - 1][j]) {
			i--;
		}
		else if (D[i][j] - 1 == D[i - 1][j - 1]) {
			LCS.push_back(i);
			i--;
			j--;
		}
	}

	for (int i = LCS.size()-1; i >= 0; i--) {
		cout << A[LCS[i]];
	}

	system("pause");

	return 0;
}