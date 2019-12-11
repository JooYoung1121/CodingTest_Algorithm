#include <iostream>
#include <cmath>
using namespace std;

int dfs(int n, int plusNum, int starNum, int maxStarNum)
{
	if (n == 1 && starNum * 2 == plusNum)
		return 1;
	else if (n <= 1)
		return 0;
	else if (starNum > maxStarNum || plusNum > maxStarNum * 2)
		return 0;

	int ret = 0;

	// * 을 추가할 경우
	if (n % 3 == 0 && (plusNum - starNum * 2) >= 2)
		ret += dfs(n / 3, plusNum, starNum + 1, maxStarNum);

	// + 를 추가할 경우
	ret += dfs(n - 1, plusNum + 1, starNum, maxStarNum);

	return ret;
}

int solution(int n) {
	int answer = 0;
	answer = dfs(n, 0,0,log(n)/log(3));
	return answer;
}

int main() {
	long long N;

	cin >> N;

	cout << solution(N);

	system("pause");
	return 0;
}