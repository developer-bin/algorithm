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
vector<int> graph[2001];
int depth;
bool visit[2001];
bool check;

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
			depth += 1;
			dfs(n_v);
			visit[n_v] = false;
			if (depth >= 5)return;
			depth -= 1;
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
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		depth = 1;
		visit[i] = true;
		dfs(i);
		visit[i] = false;
		if (depth >= 5) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
