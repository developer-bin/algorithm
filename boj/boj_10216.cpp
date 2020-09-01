#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int t;
int n;
struct node {
	int x; int y; int r;
};
vector<node> v;
vector<int> graph[3001];
bool visit[3001];
void dfs(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int n_v = graph[v][i];
		if (visit[n_v] == false) {
			visit[n_v] = true;
			dfs(n_v);
		}
	}
}
int main() {
	cin >> t;
	while (t--) {
		//init
		v.clear();
		for (int i = 0; i <= 3000; i++)graph[i].clear();
		memset(visit, false, sizeof(visit));
		//input
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			v.push_back({ x,y,r });
		}
		//solve
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				int a = abs(v[i].x - v[j].x);
				int b = abs(v[i].y - v[j].y);
				a *= a; b *= b;
				double a_to_b = sqrt(a + b);
				double radius_sum = v[i].r + v[j].r;
				if (a_to_b <= radius_sum) {
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			if (visit[i] == false) {
				visit[i] = true;
				dfs(i);
				cnt += 1;
			}
		}
		cout << cnt << '\n';
	}
}