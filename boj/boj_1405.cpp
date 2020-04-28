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
double percent[5];
int n;
double ans;
bool visit[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x,int y,int cnt,double per){
	if (cnt == n) {
		ans += per;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] == false && percent[i]!=0.0) {
			visit[nx][ny] = true;
			dfs(nx, ny, cnt + 1, per*percent[i]);
			visit[nx][ny] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> percent[i];
		percent[i] /= 100.0;
	}
	//solve
	visit[50][50] = true;
	dfs(50, 50, 0, 1.0);
	//print
	cout.setf(ios::fixed);
	cout.precision(11);
	cout << ans;
}