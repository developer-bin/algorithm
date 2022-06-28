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
int n, m;
int maps[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct vertex {
	int x; int y; int weight;
};
struct cmp {
	bool operator()(vertex a, vertex b) {
		if (a.weight > b.weight) {
			return true;
		}
		return false;
	}
};
priority_queue<vertex, vector<vertex>, cmp>pq;
bool visit[101][101];
int dist[101][101];
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			dist[i][j] = MAX_VALUE;
		}
	}
	//input
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int len = s.length();
		for (int j = 0; j < len; j++) {
			maps[i][j + 1] = s[j] - '0';
		}
	}
	//solve
	pq.push({ 1,1,0 });
	dist[1][1] = 0;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		pq.pop();
		if (visit[x][y])continue;
		visit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx, ny) == false)continue;
			int n_weight = 0;
			if (maps[nx][ny] == 1)n_weight = 1;
			else if (maps[nx][ny] == 0)n_weight = 0;
			if (dist[nx][ny] > dist[x][y] + n_weight) {
				dist[nx][ny] = dist[x][y] + n_weight;
				pq.push({ nx,ny,dist[nx][ny] });
			}
		}
	}
	cout << dist[n][m];
}
