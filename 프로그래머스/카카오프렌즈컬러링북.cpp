#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
int dx[4] = { -1,0,1,0 }; // up right down left
int dy[4] = { 0,1,0,-1 };
int solve(int type,int x, int y,int m, int n) {

    int result = 0;

    if (type != map[x][y])
        return 0;

    map[x][y] = 0;
    result++;

    for (int i = 0; i < 4; i++) {

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

        result += solve(type, nx, ny,m,n);
    }

    return result;

}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    map = picture;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 0)
                continue;

            int temp = solve(map[i][j], i,j,m,n);

            max_size_of_one_area = max(max_size_of_one_area, temp);

            number_of_area++;
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}