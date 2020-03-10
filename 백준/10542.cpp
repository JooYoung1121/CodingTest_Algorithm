#include <iostream>
#include <vector>
using namespace std;

#define MAX 500001

int Select[MAX];
int Point[MAX];

bool Mafia[MAX] = { false, }; // 마피아인거 확인
bool Chk[MAX] = { false, }; // 그 사람이 시민인지 마피아인지 판별 완료됬는지 확인

void Solve(int Idx,bool isMafia) {
	if (!Chk[Idx]) {
		Chk[Idx] = true;
		if (isMafia) // 마피아라고 정한다면 그사람은 마피아 
			Mafia[Idx] = true;
		Point[Select[Idx]]--;
		if (Point[Select[Idx]] == 0 || isMafia)
			Solve(Select[Idx], !isMafia);
	}
}

int main() {
	int N;

	cin >> N;

	int Cnt = 0;

	for (int i = 1; i <= N; i++) {
		int Number;
		cin >> Number;
		Select[i] = Number;
		Point[Number]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (Point[i] == 0) { // 지목을 한명도 안당했다면 그 사람은 마피아라고 가정 
			Solve(i, true); // 마피아인거로 가정 
		}
	}

	for (int i = 1; i <= N; i++) {
		Solve(i, false); // 전부다 확인한 뒤 남았으면 
	}

	for (int i = 1; i <= N; i++) {
		if (Mafia[i])
			Cnt++;
	}

	cout << Cnt;

	system("pause");
	return 0;
}