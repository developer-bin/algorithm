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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
//#define ll long long
using namespace std;
char maps[5][5];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int ans;
bool boundary(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}
bool check[25];
bool visit[5][5];
void combi(int idx, int cnt) {
	if (cnt == 7) {
		int s_x = 0, s_y = 0;
		for (int i = 0; i < 25; i++) {
			if (check[i]) {
				s_x = i / 5;
				s_y = i % 5;
				break;
			}
		}
		memset(visit, false, sizeof(visit));
		queue<pair<int, int>> q;
		q.push({ s_x,s_y });
		visit[s_x][s_y] = true;
		int tmp_cnt = 0;
		string tmp_s="";
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			tmp_cnt += 1;
			tmp_s += maps[x][y];
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (boundary(nx, ny) && visit[nx][ny] == false && check[nx * 5 + ny] == true) {
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
		if (tmp_cnt == 7) {
			int s_len = tmp_s.length();
			int s_cnt = 0;
			for (int i = 0; i < s_len; i++) {
				if (tmp_s[i] == 'S') s_cnt += 1;
				if (s_cnt >= 4) {
					ans += 1;
					break;
				}
			}
		}
		return;
	}
	for (int i = idx; i < 25; i++) {
		check[i] = true;
		combi(i + 1, cnt + 1);
		check[i] = false;
	}
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf(" %c", &maps[i][j]);
		}
	}
	//solve
	combi(0, 0);
	cout << ans;
}