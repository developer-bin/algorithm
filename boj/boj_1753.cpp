#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
#define MOD_VALUE 1000000000
using namespace std;
int v, e;
int s_v;
bool visit[20001];
int dist[20001];
vector<pair<int,int>> graph[20001];
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first)return true;
		else return false;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*
	int t;
	cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		cout<<'#'<<testcase<<' '<<ans<<'\n';
	}*/
	//init
	//input
	cin >> v >> e >> s_v;
	for (int i = 1; i <= e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
	}
	for (int i = 1; i <= v; i++)dist[i] = MAX_VALUE;
	//solve
	dist[s_v] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp > pq;
	pq.push({ 0,s_v });
	while (!pq.empty()) {
		int d = pq.top().first;
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
	//print
	for (int i = 1; i <= v; i++) {
		if (dist[i] == MAX_VALUE) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}