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
int n, m;
int ind[32001];
vector<int> graph[32001];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	//solve
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		ind[to] += 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)q.push(i);
	}
	while (!q.empty()) {
		int v = q.front();
		cout << v << ' ';
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			ind[n_v] -= 1;
			if (ind[n_v] == 0) {
				q.push(n_v);
			}
		}
	}
}