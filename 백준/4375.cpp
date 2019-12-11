#include <iostream>
#include <Windows.h>
using namespace std;
#pragma warning(disable: 4996)

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;

	while(scanf("%d",&n) != EOF){

		int a = 0;

		if (n == 1) {
			cout << 1 << "\n";
		}
		else {
			int count = 0;
			while (1) {
				a = (a * 10 + 1) % n;
				count++;
				if (a == 0) {
					break;
				}
			}
			cout << count << "\n";
		}
	} 

	system("pause");

	return 0;
}