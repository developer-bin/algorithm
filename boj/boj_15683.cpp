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
int maps[9][9];
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int ans=MAX_VALUE;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
struct cc_v {
	int x; int y; int cc_num;
};
vector<cc_v> v;
int checking() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (maps[i][j] == 0)cnt += 1;
		}
	}
	return cnt;
}
void dfs(int idx) {
	if (idx == v.size()) {
		ans=min(ans,checking());
		return;
	}
	int ori_maps[9][9];
	memcpy(ori_maps, maps, sizeof(maps));
	int x = v[idx].x;
	int y = v[idx].y;
	int cc_num = v[idx].cc_num;
	if (cc_num == 1) {
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (boundary(nx, ny) && maps[nx][ny]!=6) {
				maps[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
			dfs(idx + 1);
			memcpy(maps, ori_maps, sizeof(ori_maps));
		}
	}
	else if (cc_num == 2) {
		for (int i = 0; i < 2; i++) {
			int nx = x;
			int ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
			nx = x;
			ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[i+2];
				ny += dy[i+2];
			}
			dfs(idx + 1);
			memcpy(maps, ori_maps, sizeof(ori_maps));
		}
	}
	else if (cc_num == 3) {
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
			nx = x;
			ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[(i+1)%4];
				ny += dy[(i+1)%4];
			}
			dfs(idx + 1);
			memcpy(maps, ori_maps, sizeof(ori_maps));
		}
	}
	else if (cc_num == 4) {
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
			nx = x;
			ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[(i + 1) % 4];
				ny += dy[(i + 1) % 4];
			}
			nx = x;
			ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[(i + 2) % 4];
				ny += dy[(i + 2) % 4];
			}
			dfs(idx + 1);
			memcpy(maps, ori_maps, sizeof(ori_maps));
		}
	}
	else if (cc_num == 5) {
		for (int i = 0; i < 4; i++) {
			int nx = x;
			int ny = y;
			while (boundary(nx, ny) && maps[nx][ny] != 6) {
				maps[nx][ny] = 1;
				nx += dx[i];
				ny += dy[i];
			}
		}
		dfs(idx + 1);
		memcpy(maps, ori_maps, sizeof(ori_maps));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
			if (maps[i][j] != 0 && maps[i][j] != 6) {
				v.push_back({ i,j,maps[i][j] });
				maps[i][j] = 0;
			}
		}
	}
	//solve
	dfs(0);
	//print
	cout << ans;
}
