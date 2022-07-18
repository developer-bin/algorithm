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
#include <unordered_map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
ll a, b;
unordered_map<ll, bool> maps_visit;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> a >> b;
	//solve
	queue<pair<ll, int>> q;
	q.push({ a,1 });
	maps_visit[a] = true;
	while (!q.empty()) {
		ll num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == b) {
			cout << cnt;
			return 0;
		}
		ll n_num = num * 2;
		if (n_num <= b && maps_visit[n_num] == false) {
			maps_visit[n_num] = true;
			q.push({ n_num,cnt + 1 });
		}
		n_num = num * 10 + 1;
		if (n_num <= b && maps_visit[n_num] == false) {
			maps_visit[n_num] = true;
			q.push({ n_num,cnt + 1 });
		}
	}
	cout << -1;
	return 0;
}
