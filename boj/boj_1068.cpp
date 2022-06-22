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
int n;
int erase;
vector<int> graph[51];
bool visit[51];
int ans;
int root;

void dfs(int v) {
	if (v == erase)return;
	if (graph[v].size() == 0) {
		ans += 1;
		return;
	}
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1) {
			root = i;
			continue;
		}
		graph[num].push_back(i);
	}
	cin >> erase;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int v = graph[i][j];
			if (v == erase)graph[i].erase(graph[i].begin() + j);
		}
	}
	//solve
	dfs(root);
	//print
	cout << ans;
}
