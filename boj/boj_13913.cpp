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
#define MOD 1000000009
#define ll long long
using namespace std;
int n, k;
bool boundary(int x) {
	return x >= 0 && x <= 200000;
}
bool visit[200001];
int p[200001];
void print_rute() {
	stack<int> st;
	int now = k;
	int parent = p[now];
	while (true) {
		st.push(now);
		parent = p[now];
		if (parent == -1)break;
		now = parent;
	}
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> k;
	//solve
	queue<pair<int, int>> q;
	visit[n] = true;
	p[n] = -1;
	q.push({ n,0 });
	while (!q.empty()) {
		int v = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (v == k) {
			cout << cnt << '\n';
			print_rute();
			break;
		}
		int n_v = v + 1;
		if (boundary(n_v) && visit[n_v] == false) {
			visit[n_v] = true;
			p[n_v] = v;
			q.push({ n_v,cnt + 1 });
		}
		n_v = v - 1;
		if (boundary(n_v) && visit[n_v] == false) {
			visit[n_v] = true;
			p[n_v] = v;
			q.push({ n_v,cnt + 1 });
		}
		n_v = v * 2;
		if (boundary(n_v) && visit[n_v] == false) {
			visit[n_v] = true;
			p[n_v] = v;
			q.push({ n_v,cnt + 1 });
		}
	}
}