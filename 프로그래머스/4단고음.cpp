#include <cmath>
using namespace std;

int dfs(int n, int plus, int star, int maxstar)
{
	if (n == 1 && star * 2 == plus)
		return 1;
	else if (n <= 1)
		return 0;
	else if (star > maxstar || plus > maxstar * 2)
		return 0;

	int ret = 0;

	if (n % 3 == 0 && (plus - star * 2) >= 2)
		ret += dfs(n / 3, plus, star + 1, maxstar);

	ret += dfs(n - 1, plus + 1, star, maxstar);

	return ret;
}

int solution(int n) {
	int answer = 0;
	answer = dfs(n, 0,0,log(n)/log(3));
	return answer;
}