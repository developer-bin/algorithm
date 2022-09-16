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
int v, e, t;
vector<int> graph[20001];
int visit[20001];

void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == 0) {
			visit[n_v] = 3 - visit[v];
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
	cin >> t;
	while (t--) {
		//init
		memset(visit, 0, sizeof(visit));
		//input
		cin >> v >> e;
		for (int i = 1; i <= v; i++) { graph[i].clear(); }
		for (int i = 1; i <= e; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
		//solve
		for (int i = 1; i <= v; i++) {
			if (visit[i] == 0) {
				visit[i] = 1;
				dfs(i);
			}
		}
		bool check = true;
		for (int i = 1; i <= v; i++) {
			int from = i;
			for (int j = 0; j < graph[i].size(); j++) {
				int to = graph[i][j];
				if (visit[from] == visit[to]) {
					check = false;
					break;
				}
			}
			if (check == false)break;
		}
		if (check)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
