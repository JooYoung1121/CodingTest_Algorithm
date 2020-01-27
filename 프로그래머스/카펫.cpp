#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;

	int width = 3;

	while (1) {
		int height;

		height = ((brown - (width * 2)) + 4)/2;
		
		if ((width * height) - brown == red && width >= height) {
			answer.push_back(width);
			answer.push_back(height);
			break;
		}

		width++;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int brown, red;

	cin >> brown >> red;

	vector<int> result = solution(brown, red);

	for (int i = 0; i < result.size(); i++){
		cout << result[i];
	}


	system("pause");
	return 0;
}