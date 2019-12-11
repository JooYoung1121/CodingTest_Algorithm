#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;

// 뒷면, 밑면, 앞면, 왼쪽면, 오른쪽면, 윗면 순서대로 입력 

#define MAX 25

vector<int> cube[7];


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int count = 0;
	int index = 1;
	for (int i = 0; i < 24; i++) {
		int n;
		cin >> n;
		cube[index].push_back(n);
		count++;
		if (count == 4) {
			count = 0;
			index++;
		}
	}

	// 다 비교하는 함수를 만들어야 할거 같기도 하고 


	


	system("pause");
	return 0;
}