#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, L, D;
	cin >> N >> L >> D;

	int bell = 0;

	vector<int> music;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			music.push_back(1);
		}

		for (int j = 0; j < 5; j++) {
			music.push_back(0);
		}
	}

	while (1) {
		if (bell > music.size()) break;
		if (music[bell] == 0) break;
		else
			bell += D;
	}

	cout << bell;


	system("pause");
	return 0;
}