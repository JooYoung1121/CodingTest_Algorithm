#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 31
#define INF 987654321

// 2차원 배열로 푸는 법도 생각해보기 

struct edge {
	int from, to, cost;
};

int W, H, G, E;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dist[1000];
bool stone[MAX][MAX];
bool ghost[MAX][MAX];
vector<edge> Hole;

int main() {

	while (1) {
		Hole.clear();
		cin >> W >> H;
		if (W == 0 && H == 0) break;

		memset(stone, false ,sizeof(stone));
		memset(ghost, false, sizeof(ghost));

		for (int i = 0; i < W*H; i++) {
			dist[i] = INF;
		}

		dist[0] = 0;
		cin >> G;
		
		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> y >> x;
			stone[x][y] = true;
		}

		cin >> E;

		for (int i = 0; i < E; i++) {
			int x1, x2, y1, y2, t;
			cin >> y1 >> x1 >> y2 >> x2 >> t;
			edge tmp;
			tmp.from = (x1 * W) + y1;
			tmp.to = (x2 * W) + y2;
			tmp.cost = t;
			Hole.push_back(tmp);
			ghost[x1][y1] = true;
		}

		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				if (stone[x][y] || ghost[x][y] || (x == H - 1 && y == W - 1))continue;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx < 0 || nx >= H || ny < 0 || ny >= W)continue;
					if (stone[nx][ny])continue;

					edge tmp;
					tmp.from = (x * W) + y;
					tmp.to = (nx * W) + ny;
					tmp.cost = 1;
					Hole.push_back(tmp);
				}

			}
		}

		int V = W * H - G;

		for (int i = 0; i < V - 1; i++) {
			for (int j= 0; j < Hole.size(); j++) {
				if (dist[Hole[j].from] != INF && dist[Hole[j].to] > dist[Hole[j].from] + Hole[j].cost) {
					dist[Hole[j].to] = dist[Hole[j].from] + Hole[j].cost;
				}
			}
		}

		bool cycle = false;

		for (edge H : Hole) {
			if (dist[H.from] != INF && dist[H.to] > dist[H.from] + H.cost) {
				cycle = true;
				break;
			}
		}

		if (cycle) cout << "Never" << endl;
		else if (dist[W*H - 1] == INF) cout << "Impossible" << endl;
		else cout << dist[W*H - 1] << endl;
	}


	system("pause");
	return 0;
}