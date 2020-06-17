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
bool visit[101][101][4][2];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
char maps[101][101];
int n, m;
int s_x, s_y;
struct vertex {
	int x; int y; int dist; int cnt;
};
struct cmp {
	bool operator()(vertex a, vertex b) {
		return a.cnt > b.cnt;
	}
};
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int dist_convert(char c, int dist) {
	// a= /, b= 반대
	if (c == 'a') {
		if (dist == 0)return 1;
		if (dist == 1)return 0;
		if (dist == 2)return 3;
		if (dist == 3)return 2;
	}
	else if (c == 'b') {
		if (dist == 0)return 3;
		if (dist == 1)return 2;
		if (dist == 2)return 1;
		if (dist == 3)return 0;
	}
}
bool check;
int e_x, e_y;
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m ; j++) {
			scanf(" %c", &maps[i][j]);
			if (maps[i][j] == 'C' && check == false) {
				s_x = i; s_y = j;
				check = true;
			}
			else if (maps[i][j] == 'C' &&check == true) {
				e_x = i; e_y = j;
			}
		}
	}
	//solve
	priority_queue<vertex, vector<vertex>, cmp> pq;
	for (int i = 0; i < 4; i++) {
		pq.push({ s_x,s_y,i,0 });
		visit[s_x][s_y][i][0];
	}
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int dist = pq.top().dist;
		int cnt = pq.top().cnt;
		pq.pop();
		if (x == e_x && y == e_y) {
			cout << cnt;
			break;
		}
		// . 그냥 가던방향 계속전진
		int nx = x + dx[dist];
		int ny = y + dy[dist];
		if (boundary(nx, ny) && (maps[nx][ny]=='.'||maps[nx][ny]=='C') && visit[nx][ny][dist][0] == false) {
			visit[nx][ny][dist][0] == true;
			pq.push({ nx,ny,dist,cnt });
		}
		// / 만들어서 꺾음
		int n_dist = dist_convert('a', dist);
		if (visit[x][y][n_dist][1] == false) {
			visit[x][y][n_dist][1] = true;
			pq.push({ x,y,n_dist,cnt + 1 });
		}

		// 반대 거울 만들어서 꺾음
		n_dist = dist_convert('b', dist);
		if (visit[x][y][n_dist][1] == false) {
			visit[x][y][n_dist][1] = true;
			pq.push({ x,y,n_dist,cnt + 1 });
		}
	}
}