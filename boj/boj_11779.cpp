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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m;
int dist[1001];
int visit[1001];
vector<pair<int, int>> graph[1001];
int path[1001];
int s, e;
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first)return true;
		return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 1; i <= 1000; i++) {
		dist[i] = MAX_VALUE;
	}
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}
	cin >> s >> e;
	//solve
	dist[s] = 0;
	path[s] = -1;
	pq.push({ dist[s],s });
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (visit[v])continue;
		visit[v] = true;
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i].first;
			int cost = graph[v][i].second;
			if (dist[n_v] > dist[v] + cost) {
				dist[n_v] = dist[v] + cost;
				pq.push({ dist[n_v],n_v });
				path[n_v] = v;
			}
		}
	}
	//print
	cout << dist[e] << '\n';
	stack<int> st;
	int now = e;
	while (now != -1) {
		st.push(now);
		now = path[now];
	}
	cout << st.size() << '\n';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}