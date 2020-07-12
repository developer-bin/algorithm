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
int n, m;
vector<int> graph[10001];
bool visit[10001];
int ans;
vector<int> ans_v;
int bfs(int s_v) {
	queue<int> q;
	q.push(s_v);
	visit[s_v] = true;
	int cnt = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cnt += 1;
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			if (visit[n_v] == false) {
				visit[n_v] = true;
				q.push(n_v);
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> to >> from;
		graph[from].push_back(to);
	}
	//solve
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		int result = bfs(i);
		if (ans < result) {
			ans = result;
			ans_v.clear();
			ans_v.push_back(i);
		}
		else if (ans == result) {
			ans_v.push_back(i);
		}
	}
	for (int k : ans_v) {
		cout << k << ' ';
	}
}