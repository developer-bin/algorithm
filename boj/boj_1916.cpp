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
struct node {
	int from; int to; int cost;
};
int dist[1001];
vector<node> v;
int n, m;
int s_v, e_v;
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
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		v.push_back({ from,to,cost });
	}
	cin >> s_v >> e_v;
	//solve
	for (int i = 1; i <= n; i++)dist[i] = MAX_VALUE;
	dist[s_v] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].cost;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}
	//print
	cout << dist[e_v];
}