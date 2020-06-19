#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000009
#define ll long long
using namespace std;
char maps[21][21];
int w, h;
vector<pair<int, int>> dirty_point;
int s_x, s_y;
bool visit[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = MAX_VALUE;
int dist[21][21][21][21];
bool boundary(int x, int y) {
	return x >= 1 && x <= w && y >= 1 && y <= h;
}
struct vertex {
	int x; int y; int cnt;
};
void bfs(int s_x, int s_y, int e_x, int e_y) {
	memset(visit, false, sizeof(visit));
	queue<vertex> q;
	q.push({ s_x,s_y,0 });
	visit[s_x][s_y] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		if (maps[x][y] == '*' && e_x == x && e_y == y) {
			dist[s_x][s_y][e_x][e_y] = cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false) {
				if (maps[nx][ny] == '.' || maps[nx][ny]=='*') {
					visit[nx][ny] = true;
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
}
void all_dist(vector<pair<int,int>> point_v) {
	point_v.push_back({ s_x,s_y });
	for (int i = 0; i < point_v.size(); i++) {
		for (int j = 0; j < point_v.size(); j++) {
			if (i == j)continue;
			//cout << point_v[i].first << point_v[i].second << ' ' << point_v[j].first << point_v[j].second<<'\n';
			bfs(point_v[i].first, point_v[i].second, point_v[j].first, point_v[j].second);
		}
	}
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	while (true) {
		//init
		dirty_point.clear();
		ans = MAX_VALUE;
		memset(dist, 0, sizeof(dist));
		//input
		scanf("%d %d", &h, &w);
		if (h == 0 && w == 0)break;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				scanf(" %c", &maps[i][j]);
				if (maps[i][j] == 'o') {
					s_x = i;
					s_y = j;
					maps[i][j] = '.';
				}
				else if (maps[i][j] == '*') {
					dirty_point.push_back({ i,j });
				}
			}
		}
		//solve
		all_dist(dirty_point);
		vector<int> permu_v;
		for (int i = 0; i < dirty_point.size(); i++) {
			permu_v.push_back(i);
		}
		int from_x = s_x;
		int from_y = s_y;
		do {
			bool check = true;
			from_x = s_x;
			from_y = s_y;
			int to_x = 0; int to_y = 0;
			int result = 0;
			for (int i = 0; i < permu_v.size(); i++) {
				to_x = dirty_point[permu_v[i]].first;
				to_y = dirty_point[permu_v[i]].second;
				if (dist[from_x][from_y][to_x][to_y] != 0) {
					result += dist[from_x][from_y][to_x][to_y];
					from_x = to_x;
					from_y = to_y;
				}
				else {
					check = false;
					ans = -1;
					break;
				}
			}
			if (check == false)break;
			ans = min(ans, result);
		} while (next_permutation(permu_v.begin(), permu_v.end()));
		printf("%d\n", ans);
	}
}