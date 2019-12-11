#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>
using namespace std;

struct medal {
	int g = 0;
	int s = 0;
	int b = 0;
	int rank = 1;
};

vector<medal> con[1001];

int main() {
	int N, K;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a;
		medal M;
		
		cin >> a >> M.g >> M.s >> M.b;

		con[a].push_back(M);
	}

	for (int i = 1; i <= N; i++) {
		if (con[i][0].g > con[K][0].g)
		{
			con[K][0].rank++;
		}
		else if (con[i][0].g == con[K][0].g)
		{
			if (con[i][0].s > con[K][0].s) {
				con[K][0].rank++;
			}
			else if (con[i][0].s == con[K][0].s) {
				if (con[i][0].b > con[K][0].b) {
					con[K][0].rank++;
				}
			}
		}
	}


	cout << con[K][0].rank;
	system("pause");
	return 0;
}