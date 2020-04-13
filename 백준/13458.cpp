#include <iostream>
using namespace std;

#define MAX 1000001

int N , B, C;
int A[MAX];

long long result = 0;

void solve() {
	for (int i = 1; i <= N; i++) {
		int D = A[i] - B;
		if (D > 0) {
			if (D % C == 0)
				result += D / C;
			else
				result += D / C + 1;
		}
		result++;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;

	solve();

	cout << result;


	system("pause");
	return 0;
}