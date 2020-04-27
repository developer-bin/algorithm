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
char maps[51][51];
int n;
set<pair<int,int>> b_sets;
set<pair<int,int>> e_sets;
map<set<pair<int,int>>, bool> visit;
struct v {
	set<pair<int,int>> sets;
	int cnt;
};
int bfs() {
	queue<v> q;
	q.push({ b_sets, 0 });
	visit[b_sets] = true;
	while (!q.empty()) {
		int x[4] = { 0, }, y[4] = { 0, };
		set<pair<int, int>> sets = q.front().sets;
		int cnt = q.front().cnt;
		int idx = 1;
		for (auto it = sets.begin(); it != sets.end(); it++,idx++) {
			x[idx] = it->first;
			y[idx] = it->second;
		}
		q.pop();
		if (sets == e_sets) {
			return cnt;
		}
		set<pair<int, int>> n_sets;
		if (x[1] != x[2]) {
			//세로
			//상
			n_sets.clear();
			if (x[1] - 1 >= 1) {//boundary
				for (int i = x[1]; i <= x[3]; i++) {
					int nx = i - 1;
					int ny = y[1];
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size()==3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//하
			n_sets.clear();
			if (x[3] + 1 <= n) {
				for (int i = x[1]; i <= x[3]; i++) {
					int nx = i + 1;
					int ny = y[1];
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//좌
			n_sets.clear();
			if (y[1] - 1 >= 1) {
				for (int i = x[1]; i <= x[3]; i++) {
					int nx = i;
					int ny = y[1]-1;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//우
			n_sets.clear();
			if (y[1] + 1 <= n) {
				for (int i = x[1]; i <= x[3]; i++) {
					int nx = i;
					int ny = y[1] + 1;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//회전
			n_sets.clear();
			bool check = true;
			if (y[1] - 1 >= 1 && y[1] + 1 <= n) {
				for (int i = x[1]; i <= x[3]; i++) {
					int nx = i;
					int ny = y[1] - 1;
					if (maps[nx][ny] != '0') {
						check = false;
					}
					ny = y[1] + 1;
					if (maps[nx][ny] != '0') {
						check = false;
					}
				}
				if (check == false)continue;
				n_sets.insert({ x[1] + 1,y[1] - 1 });
				n_sets.insert({ x[2],y[2] });
				n_sets.insert({ x[3] - 1,y[3] + 1 });
				if (visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
		}else {
			//가로
			//상
			n_sets.clear();
			if (x[1] - 1 >= 1) {//boundary
				for (int j = y[1]; j <= y[3]; j++) {
					int nx = x[1] - 1;
					int ny = j;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//하
			n_sets.clear();
			if (x[1] + 1 <= n) {//boundary
				for (int j = y[1]; j <= y[3]; j++) {
					int nx = x[1] + 1;
					int ny = j;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//좌
			n_sets.clear();
			if (y[1] - 1 >= 1) {
				for (int j = y[1]; j <= y[3]; j++) {
					int nx = x[1];
					int ny = j - 1;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//우
			n_sets.clear();
			if (y[3] + 1 <= n) {
				for (int j = y[1]; j <= y[3]; j++) {
					int nx = x[1];
					int ny = j + 1;
					if (maps[nx][ny] == '0') {
						n_sets.insert({ nx,ny });
					}
				}
				if (n_sets.size() == 3 && visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
			//회전
			n_sets.clear();
			bool check = true;
			if (x[1] - 1 >= 1 && x[1] + 1 <= n) {
				for (int j = y[1]; j <= y[3]; j++) {
					int nx = x[1] - 1;
					int ny = j;
					if (maps[nx][ny] != '0') {
						check = false;
						continue;
					}
					nx = x[1] + 1;
					if (maps[nx][ny] != '0') {
						check = false;
						continue;
					}
				}
				if (check == false)continue;
				n_sets.insert({ x[1] - 1,y[1] + 1 });
				n_sets.insert({ x[2],y[2] });
				n_sets.insert({ x[3] + 1,y[3] - 1 });
				if (visit[n_sets] == false) {
					visit[n_sets] = true;
					q.push({ n_sets,cnt + 1 });
				}
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 'B') { 
				b_sets.insert({ i,j });
				maps[i][j] = '0';
			}
			else if (maps[i][j] == 'E') {
				e_sets.insert({ i,j }); 
				maps[i][j] = '0';
			}
		}
	}
	//solve
	cout<<bfs();
}