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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, k;
bool visit[200001];
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
	visit[n] = true;
	while (!q.empty()) {
		int v = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (v == k) {
			cout << cnt;
			break;
		}
		if (v - 1 >= 0) {
			if (visit[v - 1] == false) {
				visit[v - 1] = true;
				q.push({ v - 1,cnt + 1 });
			}
		}
		if (v + 1 <= 100000) {
			if (visit[v + 1] == false) {
				visit[v + 1] = true;
				q.push({ v + 1,cnt + 1 });
			}
		}
		if (v * 2 <= 100000) {
			if (visit[v * 2] == false) {
				visit[v * 2] = true;
				q.push({ v * 2,cnt + 1 });
			}
		}
	}
	//print
}