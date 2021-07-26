#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, m;
vector<int> graph[1001];
int ind[1001];
int ans[1001];
int cnt = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		ind[to] += 1;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)q.push(i);
	}

	while (true) {
		queue<int> n_q;
		while (!q.empty()) {
			int from = q.front();
			q.pop();
			ans[from] = cnt;
			for (int i = 0; i < graph[from].size(); i++) {
				int to = graph[from][i];
				ind[to] -= 1;
				if (ind[to] == 0) {
					n_q.push(to);
				}
			}
		}
		cnt += 1;
		if (n_q.size() == 0)break;
		q = n_q;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}