#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	int A, B, C;

	cin >> A >> B >> C;

	int da, db;

	int cnt = 0;
	while (1) {
		da = B - A;
		db = C - B;
		if (da == 1 && db == 1)
			break;
		cnt++;
		if (da >= db) {
			C = B;
			B--;
		}
		else {
			A = B;
			B++;
		}
	}
	
	cout << cnt;
	system("pause");
	return 0;
}