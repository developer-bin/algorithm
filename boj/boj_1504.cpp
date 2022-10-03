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
int n, e;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first)return true;
		return false;
	}
};
vector<pair<int, int>> graph[801];
ll dijkstra(int s, int e) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
	bool visit[801];
	int dist[801];
	memset(visit, false, sizeof(visit));
	for (int i = 1; i <= 800; i++)dist[i] = MAX_VALUE;
	pq.push({ 0,s });
	dist[s] = 0;
	while (!pq.empty()) {
		int v = pq.top().second;
		pq.pop();
		if (visit[v])continue;
		visit[v] = true;
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i].first;
			int n_cost = graph[v][i].second;
			if (dist[n_v] > dist[v] + n_cost) {
				dist[n_v] = dist[v] + n_cost;
				pq.push({ dist[n_v],n_v });
			}
		}
	}
	return (ll)dist[e];
}
int a, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> e;
	for (int i = 1; i <= e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
		graph[to].push_back({ from,cost });
	}
	cin >> a >> b;
	//solve
	ll a_to_b = dijkstra(1, a) + dijkstra(a, b) + dijkstra(b, n);
	ll b_to_a = dijkstra(1, b) + dijkstra(b, a) + dijkstra(a, n);
	ll ans = min(a_to_b, b_to_a);
	if (ans >= MAX_VALUE)ans = -1;
	//print
	cout << ans;
	return 0;
}
