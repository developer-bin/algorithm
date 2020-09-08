#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int n, m;
int maps[101][101];
int s_x, s_y, s_dist;
int e_x, e_y, e_dist;
int dx[] = { 0,0,0,1,-1 };
int dy[] = { 0,1,-1,0,0 };
bool visit[101][101][5];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
struct v {
	int x; int y; int dist; int cnt;
};
queue<v> q;
void dist_turn(int x,int y,int cnt,int dist1, int dist2) {
	if (visit[x][y][dist1] == false) {
		visit[x][y][dist1] = true;
		q.push({ x,y,dist1,cnt + 1 });
	}
	if (visit[x][y][dist2] == false) {
		visit[x][y][dist2] = true;
		q.push({ x,y,dist2,cnt + 1 });
	}
}
int main() {
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> maps[i][j];
	cin >> s_x >> s_y >> s_dist >> e_x >> e_y >> e_dist;
	//solve
	q.push({ s_x,s_y,s_dist,0 });
	visit[s_x][s_y][s_dist] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int cnt = q.front().cnt;
		q.pop();
		if (x == e_x && y == e_y && dist == e_dist) {
			cout << cnt;
			return 0;
		}
		//go
		for (int i = 1; i <= 3; i++) {
			int nx = x;
			int ny = y;
			for (int j = 1; j <= i; j++) {
				nx += dx[dist];
				ny += dy[dist];
				if (boundary(nx, ny) == false)break;
				if (maps[nx][ny] == 1)break;
			}
			if (boundary(nx, ny) && visit[nx][ny][dist] == false && maps[nx][ny]==0) {
				visit[nx][ny][dist] = true;
				q.push({ nx,ny,dist,cnt + 1 });
			}
		}
		//turn
		if (dist == 1) dist_turn(x, y, cnt, 4, 3);
		else if (dist == 2)dist_turn(x, y, cnt, 3, 4);
		else if (dist == 3)dist_turn(x, y, cnt, 1, 2);
		else dist_turn(x, y, cnt, 1, 2);
	}
	return 0;
}