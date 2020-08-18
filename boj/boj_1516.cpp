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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int ind[501];
int result_time[501];
int time[501];
int n;
vector<int> graph[501];
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i];
		while (true) {
			int num;
			cin >> num;
			if (num == -1)break;
			graph[num].push_back(i);
			ind[i] += 1;
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			result_time[i] = time[i];
		}
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			ind[n_v] -= 1;
			if (ind[n_v] == 0) {
				q.push(n_v);
			}
			result_time[n_v] = max(result_time[n_v], result_time[v] + time[n_v]);
		}
	}
	//print
	for (int i = 1; i <= n; i++) {
		cout << result_time[i]<<'\n';
	}
}