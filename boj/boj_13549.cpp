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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;
bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool boundary(int x) {
	return x >= 0 && x <= 100000;
}
bool visit[100001];
int dist[100001];
int k;
struct vertex {
	int dist; int v;
};
struct cmp {
	bool operator()(vertex a, vertex b) {
		if (a.dist > b.dist)return true;
		else return false;
	}
};
void init() {
	for (int i = 0; i <= 100000; i++)dist[i] = MAX_VALUE;
}
void input() {
	cin >> n >> k;
}
int solve() {
	priority_queue<vertex, vector<vertex>, cmp>pq;
	pq.push({ 0,n });
	dist[n] = 0;
	while (!pq.empty()) {
		int d = pq.top().dist;
		int v = pq.top().v;
		pq.pop();
		if (visit[v])continue;
		visit[v] = true;
		if (boundary(v - 1) && dist[v - 1] > dist[v] + 1) {
			dist[v - 1] = dist[v] + 1;
			pq.push({ dist[v - 1],v - 1 });
		}
		if (boundary(v + 1) && dist[v + 1] > dist[v] + 1) {
			dist[v + 1] = dist[v] + 1;
			pq.push({ dist[v + 1],v + 1 });
		}
		if (boundary(v * 2) && dist[v * 2] > dist[v]) {
			dist[v * 2] = dist[v];
			pq.push({ dist[v * 2],v * 2 });
		}
	}
	return dist[k];
}
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
	init();
	//input
	input();
	//solve and print
	cout << solve();
	return 0;
}