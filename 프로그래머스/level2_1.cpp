#include <iostream>
#include <Windows.h>
using namespace std;



int solution(int n) {
	int ans = 0;
	while (n != 0) {

		ans += n % 2;
		n /= 2;
	}
	return ans;
}

int main() {

	int N;
	cin >> N;

	cout << solution(N);




	system("pause");
	return 0;
}