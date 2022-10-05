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
#define MOD_VALUE 1000000000
using namespace std;
int n;
int maps[21][21];
int s_x, s_y;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
bool visit[21][21];
int ans;
int fish_cnt;

struct shark {
	int x; int y; int size; int eat_cnt; int time;
};
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
struct cmp {
	bool operator()(shark a, shark b) {
		if (a.x > b.x) {
			return true;
		}
		else if (a.x == b.x) {
			if (a.y > b.y)return true;
			else return false;
		}
		else return false;
	}
};
void bfs() {
	queue<shark> q;
	q.push({ s_x,s_y,2,0,0 });
	visit[s_x][s_y] = true;
	while (true) {
		int q_size = q.size();
		if (fish_cnt == 0) { break; }
		if (q_size == 0) {break; }
		queue<shark>n_q;
		priority_queue<shark, vector<shark>, cmp>eat_q;
		for (int i = 1; i <= q_size; i++) {
			int x = q.front().x;
			int y = q.front().y;
			int size = q.front().size;
			int eat_cnt = q.front().eat_cnt;
			int time = q.front().time;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (boundary(nx, ny) && visit[nx][ny] == false) {
					if (maps[nx][ny] == 0) {
						visit[nx][ny] = true;
						n_q.push({ nx,ny,size,eat_cnt,time + 1 });
					}
					else if (maps[nx][ny] == size) {
						visit[nx][ny] = true;
						n_q.push({ nx,ny,size,eat_cnt,time + 1 });
					}
					else if (maps[nx][ny] < size) {
						if (eat_cnt + 1 == size) {
							visit[nx][ny] = true;
							eat_q.push({ nx,ny,size + 1,0,time + 1 });
						}
						else {
							visit[nx][ny] = true;
							eat_q.push({ nx,ny,size,eat_cnt+1,time + 1 });
						}
					}
				}
			}
		}
		if (eat_q.size() >= 1) {
			//먹을게 있음 먹음
			int x = eat_q.top().x;
			int y = eat_q.top().y;
			int size = eat_q.top().size;
			int eat_cnt = eat_q.top().eat_cnt;
			int time = eat_q.top().time;
			ans = max(ans, time);
			q.push({ x,y,size,eat_cnt,time });
			maps[x][y] = 0;
			fish_cnt -= 1;
			memset(visit, false, sizeof(visit));
			visit[x][y] = true;
		}
		else {
			//먹을거 없음 그냥 다음으로 감
			q = n_q;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 9) { s_x = i; s_y = j; maps[i][j] = 0; }
			if (1 <= maps[i][j] && maps[i][j] <= 6)fish_cnt += 1;
		}
	}
	//solve
	bfs();
	//print
	cout << ans;
	return 0;
}
