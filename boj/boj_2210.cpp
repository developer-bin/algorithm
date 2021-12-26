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
#define ll long long
using namespace std;
char maps[6][6];

bool boundary(int x, int y) {
	return x >= 1 && x <= 5 && y >= 1 && y <= 5;
}
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool visit[6][6];
set<string> sets;
void dfs(int x, int y, string s) {

	int len = s.length();
	if (len == 6) {
		sets.insert(s);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (boundary(nx, ny)) {
			string n_s = s;
			n_s.push_back(maps[nx][ny]);
			dfs(nx, ny, n_s);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			string s;
			s.push_back(maps[i][j]);
			dfs(i, j, s);
		}
	}
	cout << sets.size();
}