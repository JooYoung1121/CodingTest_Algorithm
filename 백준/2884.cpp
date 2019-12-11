#include <iostream>
#include <Windows.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int H, M;

	cin >> H >> M;

	if (M >= 45)
		M -= 45;
	else {
		int tmp;
		tmp = 45 - M;

		M = 60 - tmp;
		if (H == 0)
			H = 23;
		else
			H--;
	}

	cout << H << ' ' << M;

	system("pause");
	return 0;
}