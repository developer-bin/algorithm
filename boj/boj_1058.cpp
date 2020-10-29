#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;
int n;
char map[51][51];
vector<int> graph[51];
bool visit[51];
int ans = -200000000;
int bfs(int start_v) {
	int cnt = 0;
	memset(visit, false, sizeof(visit));
	visit[start_v] = true;
	queue<pair<int,int>> q;
	q.push({ start_v,0 });
	while (!q.empty()) {
		int v = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (depth == 1 || depth == 2)cnt += 1;
		if (depth == 3)break;
		for (int i = 0; i < graph[v].size(); i++) {
			int n_v = graph[v][i];
			if (visit[n_v] == false) {
				visit[n_v] = true;
				q.push({ n_v,depth + 1 });
			}
		}
	}
	return cnt;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			scanf(" %c", &c);
			if (c == 'Y') {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		ans=max(ans,bfs(i));
	}
	printf("%d", ans);
}