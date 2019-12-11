#include <iostream>
using namespace std;

#define MAX 101


int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;

		cin >> N;
		bool room[MAX] = { false, };

		for (int j = 1; j <= N; j++) {
			for (int m = j; m <= N; m += j) {
				if (room[m])
					room[m] = false;
				else
					room[m] = true;
			}
		}

		int _count = 0;
		for (int j = 1; j <= N; j++) {
			if (room[j])
				_count++;
		}
		cout << _count << endl;
	}


	return 0;
}