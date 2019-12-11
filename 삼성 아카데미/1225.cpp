#include <iostream>
#include <queue>
using namespace std;

int main() {

	int N;
	do {

		cin >> N;

		queue<int> num;
		for (int i = 0; i < 8; i++) {
			int a;
			cin >> a;
			num.push(a);
		}
		while (1) {
			bool chk = true;
			for (int i = 1; i <= 5; i++) {
				int t = num.front();
				num.pop();
				t -= i;
				if (t <= 0)
				{
					num.push(0);
					chk = false;
					break;
				}
				else
					num.push(t);
			}

			if (!chk)
				break;
		}
		cout << "#" << N << " ";

		while (!num.empty()) {
			int n = num.front();
			num.pop();
			cout << ' ' << n;
		}
		cout << endl;

	} while (getc(stdin) == ' ');


	return 0;
}