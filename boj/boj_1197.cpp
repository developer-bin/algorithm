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
bool visit[10001];
vector<pair<int, int>> graph[10001];
int v, e;
int ans;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second)return true;
		return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> v >> e;
	for (int i = 1; i <= e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to,cost });
		graph[to].push_back({ from,cost });
	}
	//solve
	visit[1] = true;
	for (int i = 0; i < graph[1].size(); i++) {
		int to = graph[1][i].first;
		int cost = graph[1][i].second;
		pq.push({ to,cost });
	}
	while (!pq.empty()) {
		int v = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (visit[v])continue;
		visit[v] = true;
		ans += cost;
		for (int i = 0; i < graph[v].size(); i++) {
			int to = graph[v][i].first;
			int cost = graph[v][i].second;
			pq.push({ to,cost });
		}
	}
	cout << ans;
}
