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
vector<int> graph[1001];
bool visit[1001];
int ans;
void dfs(int v) {
	visit[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false) {
			dfs(n_v);
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
		if (visit[i] == false) {
			dfs(i);
			ans += 1;
		}
	}
	cout << ans;
	return 0;
}