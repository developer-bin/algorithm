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
char maps[21][21];
bool visit[21][21][21][21];
int x, y, a, b;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans=-1;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
struct vertex {
	int x; int y; int a; int b; int cnt;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	scanf("%d %d",&n,&m);
	bool check = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &maps[i][j]);
			if (maps[i][j] == 'o' && check==false) {
				check = true;
				x = i; y = j;
				maps[i][j] = '.';
			}
			else if (maps[i][j] == 'o' && check) {
				a = i; b = j;
				maps[i][j] = '.';
			}
		}
	}
	//solve
	queue<vertex> q;
	q.push({ x,y,a,b,0 });
	visit[x][y][a][b] = true;
	check = false;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int a = q.front().a;
		int b = q.front().b;
		int cnt = q.front().cnt;
		if (cnt >= 10) {
			ans = -1;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int na = a + dx[i];
			int nb = b + dy[i];
			if (boundary(nx, ny)==false && boundary(na, nb)==false) { 
				continue; 
			}
			if (boundary(nx, ny) && boundary(na, nb)) {
				bool xy_check = false;
				bool ab_check = false;
				if (maps[nx][ny] == '.')xy_check = true;
				if (maps[na][nb] == '.')ab_check = true;
				if (xy_check && ab_check) {
					visit[nx][ny][na][nb] = true;
					q.push({ nx,ny,na,nb,cnt + 1 });
				}
				else if (xy_check) {
					visit[nx][ny][a][b] = true;
					q.push({ nx,ny,a,b,cnt + 1 });
				}
				else if (ab_check) {
					visit[x][y][na][nb] = true;
					q.push({ x,y,na,nb,cnt + 1 });
				}
			}else if (boundary(nx, ny) || boundary(na, nb)) {
				check = true;
				ans = cnt + 1;
				break;
			}
		}
		if (check)break;
	}
	cout << ans;
}
