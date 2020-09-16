#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
using namespace std;
string s1;
string s2;
int a[7];
int maps[21][21];
int x, y;
int n, m;
int k;
queue<int> cmd;
int dx[] = { 0,0,0,-1,1 };
int dy[] = { 0,1,-1,0,0 };
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void rotate(int op) {
	int n_a[7];
	for (int i = 1; i <= 6; i++) {
		n_a[i] = a[i];
	}
	switch (op) {
	case 1:
		n_a[3] = a[1];
		n_a[6] = a[3];
		n_a[4] = a[6];
		n_a[1] = a[4];
		break;
	case 2:
		n_a[1] = a[3];
		n_a[3] = a[6];
		n_a[6] = a[4];
		n_a[4] = a[1];
		break;
	case 3:
		n_a[2] = a[1];
		n_a[6] = a[2];
		n_a[5] = a[6];
		n_a[1] = a[5];
		break;
	case 4:
		n_a[1] = a[2];
		n_a[2] = a[6];
		n_a[6] = a[5];
		n_a[5] = a[1];
		break;
	}
	for (int i = 1; i <= 6; i++) {
		a[i] = n_a[i];
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	
	//input
	cin >> n >> m >> x >> y >> k;
	x += 1; y += 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maps[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int command;
		cin >> command;
		cmd.push(command);
	}
	//solve
	while (!cmd.empty()) {
		int op = cmd.front();
		cmd.pop();
		int nx = x + dx[op];
		int ny = y + dy[op];
		if (boundary(nx, ny) == false)continue;
		rotate(op);
		if (maps[nx][ny] == 0) {
			maps[nx][ny] = a[6];
		}
		else if (maps[nx][ny] != 0) {
			a[6] = maps[nx][ny];
			maps[nx][ny] = 0;
		}
		x = nx; y = ny;
		cout << a[1] << '\n';
	}
	//print
	
}