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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
vector<pair<int, int>> virus_pos_v;
int n, m;
int maps[51][51];
vector<pair<int, int>> start_pos;
struct vertex {
	int x; int y; int cnt;
};
bool visit[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int real_zero_cnt;
int ans = MAX_VALUE;
int test[51][51];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int bfs() {
	memset(visit, false, sizeof(visit));
	memset(test, 0, sizeof(test));
	int virus_time = 0;
	int real_cnt = 0;
	queue<vertex> q;
	for (int i = 0; i < start_pos.size(); i++) {
		q.push({ start_pos[i].first,start_pos[i].second,0 });
		visit[start_pos[i].first][start_pos[i].second] = true;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		if (maps[x][y] == 0)real_cnt += 1;
		test[x][y] = cnt;
		virus_time = max(virus_time, cnt);
		if (real_cnt == real_zero_cnt) {
			return virus_time;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				if (maps[nx][ny] == 0 || maps[nx][ny] == 2) {
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
	return -1;
}
void combi(int idx, int cnt) {
	if (cnt == m) {
		int mid_ans = bfs();
		if (mid_ans != -1) {
			ans = min(ans, mid_ans);
		}
		return;
	}
	for (int i = idx; i < virus_pos_v.size(); i++) {
		start_pos.push_back({ virus_pos_v[i].first,virus_pos_v[i].second });
		combi(i + 1, cnt + 1);
		start_pos.pop_back();
	}
}
int main() {
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 2) {
				virus_pos_v.push_back({ i,j });
			}
			else if (maps[i][j] == 0) {
				real_zero_cnt += 1;
			}
		}
	}
	//solve
	combi(0, 0);
	//print
	if (ans == MAX_VALUE)ans = -1;
	cout << ans;
}