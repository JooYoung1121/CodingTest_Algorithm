#include <iostream>

using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int r = x%y;
		x = y;
		y = r;
	}
	return x;
}

int main()
{
	int a1, a2, b1, b2;

	cin >> a1 >> a2 >> b1 >> b2;

	int gcd_num = gcd(a2, b2);

	int result_b = (a2*b2) / gcd_num;
	int result_a = (result_b / a2*a1) + (result_b / b2*b1);

	gcd_num = gcd(result_a, result_b);

	cout << result_a / gcd_num << " " << result_b / gcd_num << endl;

	return 0;
}