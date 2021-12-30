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

int r, c;
int ans = MIN_VALUE;
char maps[21][21];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool visit[21][21];
bool alpha[26];

bool boundary(int x, int y) {
	return x >= 1 && x <= r && y >= 1 && y <= c;
}

void state(int x, int y, int cnt) {
	ans = max(ans, cnt);

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && visit[nx][ny] == false && alpha[maps[nx][ny]-'A'] == false) {
			visit[nx][ny] = true;
			alpha[maps[nx][ny]-'A'] = true;
			state(nx, ny, cnt + 1);
			visit[nx][ny] = false;
			alpha[maps[nx][ny]-'A'] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> maps[i][j];
		}
	}

	alpha[maps[1][1]-'A'] = true;
	visit[1][1] = true;
	state(1, 1, 1);

	cout << ans;
}