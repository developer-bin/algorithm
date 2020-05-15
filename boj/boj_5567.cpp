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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m;
vector<int> graph[501];
bool visit[501];
int ans = -1;
void bfs(int sv) {
	queue<pair<int, int>> q;
	q.push({ sv,0 });
	visit[sv] = true;
	while (!q.empty()) {
		int v = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt == 3)break;
		ans += 1;
		for (int i = 0; i < graph[v].size(); i++) {
			int nv = graph[v][i];
			if (visit[nv] == false) {
				visit[nv] = true;
				q.push({ nv,cnt + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	//solve
	bfs(1);
	//print
	cout << ans;
}