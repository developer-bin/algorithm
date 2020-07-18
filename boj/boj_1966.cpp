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
int t;
int n, m;
int print_num;
int weight[101];
bool q_visit[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		//init
		memset(q_visit, false, sizeof(q_visit));
		//input
		cin >> n >> m;
		//solve
		print_num = m + 1;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			cin >> weight[i];
			q.push(i);
			q_visit[i] = true;
		}
		int ans = 1;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			bool check = true;
			for (int i = 1; i <= n; i++) {
				if (now == i)continue;
				if (q_visit[i] == false)continue;
				if (weight[now] < weight[i]) {
					q.push(now);
					check = false;
					break;
				}
			}
			if (check) {
				if (print_num == now) {
					cout << ans << '\n';
					break;
				}
				ans += 1;
				q_visit[now] = false;
			}
		}
	}
	
}