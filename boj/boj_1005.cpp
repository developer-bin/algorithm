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
#include <unordered_map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int t;
int n, k;
int time[1001];
int ind[1001];
int result_time[1001];
vector<int> graph[1001];
int w;
void bfs(queue<int> &q) {
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			ind[n_v] -= 1;
			if (ind[n_v] == 0) {
				q.push(n_v);
			}
			result_time[n_v] = max(result_time[n_v], result_time[v] + time[n_v]);
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
	//solve
	while (t--) {
		memset(ind, 0, sizeof(ind));
		memset(result_time, 0, sizeof(result_time));
		for (int i = 1; i <= 1000; i++) {
			graph[i].clear();
		}
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}
		for (int i = 1; i <= k; i++) {
			int from, to;
			cin >> from >> to;
			ind[to] += 1;
			graph[from].push_back(to);
		}
		cin >> w;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) {
				q.push(i);
				result_time[i] = time[i];
			}
		}
		bfs(q);
		cout << result_time[w] << '\n';
	}
}