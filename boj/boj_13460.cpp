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
char maps[11][11];
bool visit[11][11][11][11];
int srx, sry, sbx, sby, ex, ey;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
struct v {
	int rx; int ry; int bx; int by; int cnt;
};
int roll() {
	queue<v> q;
	visit[srx][sry][sbx][sby] = true;
	q.push({ srx,sry,sbx,sby,0 });
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt >= 11)return -1;
		if (maps[rx][ry] == 'O') {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nrx = rx;
			int nry = ry;
			int nbx = bx;
			int nby = by;
			int r_step_cnt = 0;
			int b_step_cnt = 0;
			//빨간 굴리기
			while (boundary(nrx, nry) && maps[nrx][nry] == '.') {
				nrx += dx[i];
				nry += dy[i];
				r_step_cnt += 1;
			}
			//구멍이면 뒤로안물림
			if (maps[nrx][nry] != 'O') {
				nrx -= dx[i];
				nry -= dy[i];
			}
			//파란 굴리기
			while (boundary(nbx, nby) && maps[nbx][nby] == '.') {
				nbx += dx[i];
				nby += dy[i];
				b_step_cnt += 1;
			}
			//구멍이면 뒤로안물림
			if (maps[nbx][nby] != 'O') {
				nbx -= dx[i];
				nby -= dy[i];
			}
			//구멍에 동시에드가던가 파랑이 드가면 안됨
			if (nrx == nbx && nry == nby && maps[nrx][nry] == 'O')continue;
			if (maps[nbx][nby] == 'O')continue;
			//같은위치일때 더 많이구른공을 한칸물림 안후“
			if (nrx == nbx && nry == nby) {
				if (r_step_cnt > b_step_cnt) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			//다음상태로 가기위해
			if (visit[nrx][nry][nbx][nby] == false) {
				visit[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby,cnt + 1 });
			}
		}
	}
	return -1;
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
			if (maps[i][j] == 'R') {
				srx = i;
				sry = j;
				maps[i][j] = '.';
			}
			else if (maps[i][j] == 'B') {
				sbx = i;
				sby = j;
				maps[i][j] = '.';
			}
			else if (maps[i][j] == 'O') {
				ex = i;
				ey = j;
			}
		}
	}
	//solve and print
	cout<<roll();
}
