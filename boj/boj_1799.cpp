#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
int maps[11][11];
int ans_black,ans_white;
bool checking(int x,int y) {
	int ori_x=x, ori_y = y;
	//왼쪽상단 오른하단 대각
	while (true) {
		x -= 1;
		y -= 1;
		if (x < 1 || y < 1)break;
		if (maps[x][y] == 2)return false;
	}
	x = ori_x;
	y = ori_y;
	while (true) {
		x += 1;
		y += 1;
		if (x > n || y > n)break;
		if (maps[x][y] == 2)return false;
	}
	//오른상단 왼쪽하단 대각
	x = ori_x;
	y = ori_y;
	while (true) {
		x -= 1;
		y += 1;
		if (x < 1 || y > n)break;
		if (maps[x][y] == 2)return false;
	}
	x = ori_x;
	y = ori_y;
	while (true) {
		x += 1;
		y -= 1;
		if (x > n || y < 1)break;
		if (maps[x][y] == 2)return false;
	}
	return true;
}
pair<int, int> nx_ny_cal_white(int x, int y) {
	int nx = x;
	int ny = y;
	ny += 2;
	if (ny > n) {
		nx += 1;
		if (nx % 2 == 1) {
			ny = 2;
		}
		else {
			ny = 1;
		}
	}
	return { nx,ny };
}
void dfs_white(int x, int y, int cnt) {
	ans_white = max(ans_white, cnt);
	if (x > n) {
		return;
	}
	if (maps[x][y] == 1) {
		maps[x][y] = 2;
		if (checking(x,y)) {
			auto pair_nx_ny=nx_ny_cal_white(x, y);
			dfs_white(pair_nx_ny.first, pair_nx_ny.second, cnt + 1);//놓을수잇으면 놓음
		}
		maps[x][y] = 1;
		auto pair_nx_ny = nx_ny_cal_white(x, y);
		dfs_white(pair_nx_ny.first, pair_nx_ny.second, cnt);//놓을수잇는자리도 그냥안놓고다음으로가봄
	}
	else {
		auto pair_nx_ny = nx_ny_cal_white(x, y);
		dfs_white(pair_nx_ny.first, pair_nx_ny.second, cnt);//못놓는자리는 넘어감
	}
}
pair<int, int> nx_ny_cal_black(int x, int y) {
	int nx = x;
	int ny = y;
	ny += 2;
	if (ny > n) {
		nx += 1;
		if (nx % 2 == 1) {
			ny = 1;
		}
		else {
			ny = 2;
		}
	}
	return { nx,ny };
}
void dfs_black(int x, int y, int cnt) {
	ans_black = max(ans_black, cnt);
	if (x > n) {
		return;
	}
	if (maps[x][y] == 1) {
		maps[x][y] = 2;
		if (checking(x, y)) {
			auto pair_nx_ny = nx_ny_cal_black(x, y);
			dfs_black(pair_nx_ny.first, pair_nx_ny.second, cnt + 1);//놓을수잇으면 놓음
		}
		maps[x][y] = 1;
		auto pair_nx_ny = nx_ny_cal_black(x, y);
		dfs_black(pair_nx_ny.first, pair_nx_ny.second, cnt);//놓을수잇는자리도 그냥안놓고다음으로가봄
	}
	else {
		auto pair_nx_ny = nx_ny_cal_black(x, y);
		dfs_black(pair_nx_ny.first, pair_nx_ny.second, cnt);//못놓는자리는 넘어감
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	dfs_white(1, 2, 0);
	dfs_black(1, 1, 0);
	//print
	cout << ans_white+ans_black;
}