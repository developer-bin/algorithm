#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;

int t;
int n, m;
int ans;
vector<int> graph[1001];
bool visit[1001];

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
			ans += 1;
			dfs(n_v);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		ans = 0;
		memset(visit, false, sizeof(visit));
		for (int i = 1; i <= 1000; i++) {
			graph[i].clear();
		}

		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		visit[1]=true;
		dfs(1);

		cout << ans << "\n";
	}
}