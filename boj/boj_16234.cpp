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
#define MOD 9901
#define ll long long
using namespace std;
struct a_vertex {
	bool dist[4];//0ºÏ 1µ¿ 2³² 3¼­
	int num;
};
int n, l, r;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[51][51];
struct a_vertex maps[51][51];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
bool open_door() {
	bool check = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (boundary(nx, ny) && maps[i][j].dist[k] == false && (abs(maps[i][j].num-maps[nx][ny].num)>=l && abs(maps[i][j].num - maps[nx][ny].num)<=r)) {
					maps[i][j].dist[k] = true;
					check = true;
				}
			}
		}
	}
	return check;
}
void start_bfs(int s_x, int s_y) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	int sum = 0;
	q.push({ s_x,s_y });
	visit[s_x][s_y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		sum += maps[x][y].num;
		v.push_back({ x,y });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) && visit[nx][ny] == false && maps[x][y].dist[i]==true) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	sum = sum / (int)v.size();
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		maps[x][y].num = sum;
	}
}
void move_people() {
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j] == false) {
				start_bfs(i, j);
			}
		}
	}
}
void all_close() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				maps[i][j].dist[k] = false;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j].num;
		}
	}
	//solve
	int cnt = 0;
	while (true) {
		if(open_door()==false)break;
		move_people();
		all_close();
		cnt += 1;
	}
	cout << cnt;
}