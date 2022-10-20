#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int n;
int a[1001];
int d[1001];
int dist[1001];
int ans;
int max_idx;

void go(int v) {
	if (v == -1)return;
	go(dist[v]);
	cout << a[v] << ' ';
}
int dfs(int idx) {
	int& result = d[idx];
	if (result != -1)return result;
	result = 1;
	for (int i = idx - 1; i >= 1; i--) {
		if (a[i] < a[idx]) {
			dist[idx] = i;
			result = max(result, dfs(i) + 1);
		}
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(dist, -1, sizeof(dist));
	//memset(d, 1, sizeof(d));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (a[j] < a[i] && d[j]+1>d[i]) {
				d[i] = d[j] + 1;
				dist[i] = j;
			}
		}
	}
	cout << *max_element(d + 1, d + 1 + n)<<'\n';
	int tmp = MIN_VALUE;
	for (int i = 1; i <= n; i++) {
		if (tmp < d[i]) {
			tmp = d[i];
			max_idx = i;
		}
	}
	go(max_idx);
}
