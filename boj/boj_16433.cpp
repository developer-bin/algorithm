#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
char maps[100][100];
int n, r, c;
bool visit[100][100];
queue < pair<int, int>>q;
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 99; j++) {
			maps[i][j] = '.';
		}
	}
	//input
	cin >> n >> r >> c;
	//solve
	maps[r][c] = 'v';
	visit[r][c] = true;
	q.push({ r,c });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		maps[x][y] = 'v';
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (boundary(nx,ny) && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << maps[i][j];
		}cout << '\n';
	}
}