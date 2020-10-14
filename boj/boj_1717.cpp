#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <tuple>
#include <cmath>
#include <map>
#define MAX_VALUE 200000000
#define MIN_VALUE -200000000
#define MOD_VALUE 1000000000
using namespace std;
//int dx[] = { 0,0,0,-1,1 };
//int dy[] = { 0,1,-1,0,0 };
//bool boundary(int x, int y) {
//	return x >= 1 && x <= n && y >= 1 && y <= m;
//}
int parent[1000001];
int n, m;
int Find(int v) {
	if (parent[v] == v)return v;
	else return parent[v] = Find(parent[v]);
}
void Union(int v1, int v2) {
	int v1_root = Find(v1);
	int v2_root = Find(v2);
	parent[v2_root] = v1_root;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 1; i <= 1000000; i++)parent[i] = i;
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0)Union(a, b);
		if (op == 1) {
			int a_root = Find(a);
			int b_root = Find(b);
			if (a_root == b_root)cout << "YES\n";
			else cout << "NO\n";
		}
	}
	//solve
	
	//print
	
}