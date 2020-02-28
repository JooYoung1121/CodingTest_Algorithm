#include <iostream>
using namespace std;

int main() {

	int N, K;

	cin >> N >> K;

	int A, B;
	A = 1;
	B = 1;
	for (int i = 1; i <= K; i++) {
		A *= N;
		B *= i;
		N -= 1;
	}

	cout << A / B << endl;

	return 0;
}