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
int route_cnt;
int route_time = MAX_VALUE;

bool boundary(int x) {
	return x >= 0 && x <= 1000000;
}
bool visit[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> k;
	//solve
	queue<pair<int, int>> q;
	q.push({ n,0 });
	while (!q.empty()) {
		int v = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visit[v] = true;
		if (route_time < cnt) {
			break;
		}
		if (v == k) {
			if (route_time > cnt) {
				route_time = cnt;
			}
			route_cnt += 1;
		}
		int n_v = v + 1;
		if (boundary(n_v) && visit[n_v] == false) {
			q.push({ n_v,cnt + 1 });
		}
		n_v = v - 1;
		if (boundary(n_v) && visit[n_v] == false) {
			q.push({ n_v,cnt + 1 });
		}
		n_v = v * 2;
		if (boundary(n_v) && visit[n_v] == false) {
			q.push({ n_v,cnt + 1 });
		}
	}
	cout << route_time << '\n' << route_cnt;
}