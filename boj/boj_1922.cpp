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
int parent[1001];
int n, m;

int Find(int v) {
	if (parent[v] == v)return v;
	else {
		return parent[v] = Find(parent[v]);
	}
}
void Union(int v1, int v2) {
	int p1 = Find(v1);
	int p2 = Find(v2);
	parent[p1] = p2;
}
vector<tuple<int, int, int>> edge;
int ans;
bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
	int f, t, c;
	tie(f, t, c) = a;
	int f2, t2, c2;
	tie(f2, t2, c2) = b;
	if (c < c2)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	for (int i = 1; i <= 1000; i++) {
		parent[i] = i;
	}
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		edge.push_back({ from,to,cost });
	}
	//solve
	sort(edge.begin(), edge.end(), cmp);
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		tie(from, to, cost) = edge[i];
		if (Find(from) != Find(to)) {
			Union(from, to);
			ans += cost;
		}
	}
	cout << ans;
}