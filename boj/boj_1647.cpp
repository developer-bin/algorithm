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
vector<tuple<int, int, int>> edge;
int p[100001];
int ans;
int end_cost;

bool cmp(tuple<int, int, int> t1, tuple<int, int, int> t2) {
	int a, b, c;
	int x, y, z;
	tie(a, b, c) = t1;
	tie(x, y, z) = t2;

	if (c < z)return true;
	return false;
}

int Find(int v) {
	if (v == p[v])return v;
	else return p[v] = Find(p[v]);
}

void Union(int v1, int v2) {
	int p1 = Find(v1);
	int p2 = Find(v2);
	p[p1] = p2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 100000; i++) {
		p[i] = i;
	}

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from,to,cost });
	}

	sort(edge.begin(), edge.end(), cmp);

	for (int i = 0; i < edge.size(); i++) {
		int from, to, cost;
		tie(from, to, cost) = edge[i];

		if (Find(from) != Find(to)) {
			ans += cost;
			Union(from, to);
			end_cost = cost;
		}
	}

	cout << ans - end_cost;
}