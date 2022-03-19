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
bool visit[101];
int ladder[101];
int snake[101];
int n, m;

struct vertex {
	int x; int cnt;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int from, to;
		cin >> from >> to;
		ladder[from] = to;
	}
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		snake[from] = to;
	}
	//solve
	queue<vertex> q;
	q.push({ 1,0 });
	visit[1] = true;
	while (!q.empty()) {
		int v = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if (v == 100) {
			cout << cnt;
			break;
		}
		for (int i = 1; i <= 6; i++) {
			int n_v = v + i;
			if (n_v <= 100) {
				if (ladder[n_v] != 0) {
					n_v = ladder[n_v];
				}
				else if (snake[n_v] != 0) {
					n_v = snake[n_v];
				}
				if (visit[n_v] == false) {
					visit[n_v] = true;
					q.push({ n_v,cnt + 1 });
				}
			}
		}
	}
	return 0;
}