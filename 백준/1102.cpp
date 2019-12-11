#include <iostream>
using namespace std;

#define MAX 17

int ele[MAX][MAX];
int D[MAX][1 << 16]; // N*NÀÌ¹Ç·Î 

int main() {
	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> ele[i][j];
		}
	}





	return 0;
}