#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int N, D;
		cin >> N >> D;
		int dist = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int tower;
			cin >> tower;
			if (tower == 0) {
				dist++;
				if (dist == D){
					dist = 0;
					cnt++;
				}
			}
			else
				dist = 0;
		}
		cout << "#" << test_case << " " << cnt << endl;
	}
	return 0;
}