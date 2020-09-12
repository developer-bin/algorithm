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
vector<int> graph1[100];
vector<int> graph2[100];
int n,m;
bool visit[100];
int weight[100];
int ans;
void dfs1(int v) {
	for (int i = 0; i < graph1[v].size(); i++) {
		int n_v = graph1[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
			weight[n_v] += 1;
			dfs1(n_v);
		}
	}
}
void dfs2(int v) {
	for (int i = 0; i < graph2[v].size(); i++) {
		int n_v = graph2[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
			weight[n_v] += 1;
			dfs2(n_v);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph1[from].push_back(to);
		graph2[to].push_back(from);
	}
	//solve
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs1(i);
	}
	for (int i = 1; i <= n; i++) {
		if (weight[i] >= (n / 2 + 1))ans += 1;
	}
	memset(weight, 0, sizeof(weight));
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		visit[i] = true;
		dfs2(i);
	}
	for (int i = 1; i <= n; i++) {
		if (weight[i] >= (n / 2 + 1))ans += 1;
	}
	//print
	cout << ans;
}