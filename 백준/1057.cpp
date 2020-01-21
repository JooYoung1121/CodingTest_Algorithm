#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	int kim, lim;

	cin >> N >> kim >> lim;
	
	int cnt = 1;

	if (kim > lim)
		swap(kim, lim);

	while (1) {
		
		if (kim % 2 == 1 &&  kim + 1 == lim)
			break;
		
		if (kim % 2 != 0)
			kim++;
		if (lim % 2 != 0)
			lim++;
		kim /= 2;
		lim /= 2;

		if (kim == 1 && lim == 1) {
			cnt = -1;
			break;
		}

		cnt++;
	}


	cout << cnt;


	system("pause");
	return 0;
}