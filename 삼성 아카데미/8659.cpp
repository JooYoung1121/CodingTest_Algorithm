#include <iostream>
#include <Windows.h>
using namespace std;


int result;
#define MAX 94

long long D[MAX];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K;

		cin >> K;

		D[0] = 0;
		D[1] = 1;
		D[2] = 1;

		for (int i = 3; i <= MAX; i++) {
			D[i] = D[i - 1] + D[i - 2];
		}

		cout << "#" << test_case << " " << D[K + 2] << " " << D[K + 1] << endl;



	}

	system("pause");
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}