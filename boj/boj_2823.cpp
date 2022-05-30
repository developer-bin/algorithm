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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
char maps[11][11];
int r, c;
int s_x, s_y;

bool boundary(int x, int y) {
	return x >= 1 && x <= r && y >= 1 && y <= c;
}
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[11][11];
bool u_turn_check;
void dfs(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny) && maps[nx][ny] == '.') {
			if (visit[nx][ny] == false) {
				visit[nx][ny] = true;
				dfs(nx, ny);
				if (u_turn_check == true)return;
			}
			cnt += 1;
		}
	}
	if (cnt == 1) {
		u_turn_check = true;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		string s;
		cin >> s;
		int s_len = s.length();
		for (int k = 0; k < s_len; k++) {
			maps[i][k + 1] = s[k];
			if (maps[i][k + 1] == '.') {
				s_x = i;
				s_y = k + 1;
			}
		}
	}
	//solve
	dfs(s_x, s_y);
	//print
	if (u_turn_check)cout << 1;
	else cout << 0;
}