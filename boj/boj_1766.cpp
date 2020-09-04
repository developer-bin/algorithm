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
vector<int> graph[32001];
int ind[32001];
struct cmp {
	bool operator()(int a, int b) {
		if (a > b)return true;
		return false;
	}
};
priority_queue<int, vector<int>, cmp> pq;
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		ind[to] += 1;
	}
	//solve
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)pq.push(i);
	}
	while (!pq.empty()) {
		int v = pq.top();
		pq.pop();
		cout << v<<' ';
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			ind[n_v] -= 1;
			if (ind[n_v] == 0) {
				pq.push(n_v);
			}
		}
	}
	//print
	return 0;
}