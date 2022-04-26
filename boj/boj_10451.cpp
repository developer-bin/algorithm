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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n, t;
int visit[1001];
int graph[1001];

bool dfs(int s_v,int v) {
	visit[v] = s_v;
	int n_v = graph[v];
	if (visit[n_v] == 0) {
		return dfs(s_v,n_v);
	}
	else if (n_v == s_v) {
		return true;
	}
	else if (visit[n_v] == s_v) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int ans = 0;
		memset(visit, 0, sizeof(visit));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> graph[i];
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i]==0) {
				if(dfs(i,i))ans+=1;
			}
		}
		cout << ans << '\n';
	}
}