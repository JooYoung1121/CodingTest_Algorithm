#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int N, K, M; // 총 인원, 죽는 번호 , 동호 번호

	cin >> N >> K >> M;
	int answer;

	for (answer = 1; answer <= N; answer++) {
		int Dong_idx;

		if ((K % (N - answer + 1)) == 0) {
			Dong_idx = N - answer + 1;
		}
		else
			Dong_idx = K % (N - answer + 1);

		if (M == Dong_idx)
			break;
		else
		{
			if (M > Dong_idx) {
				M = M - Dong_idx;
			}
			else {
				M = M - Dong_idx + N - answer + 1;
			}
		}
	}

	cout << answer;

	system("pause");
	return 0;
}