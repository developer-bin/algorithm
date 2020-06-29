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
int n;
int cost[21][21];
bool visit[21];
int ans = MAX_VALUE;
void combi(int idx, int cnt, int end_cnt) {
	if (cnt == end_cnt) {
		vector<int> team1, team2;
		for (int i = 1; i <= n; i++) {
			if (visit[i]) {
				team1.push_back(i);
			}
			else {
				team2.push_back(i);
			}
		}
		int team1_sum = 0, team2_sum = 0;
		for (int i = 0; i < team1.size() - 1; i++) {
			for (int j = i + 1; j < team1.size(); j++) {
				team1_sum += cost[team1[i]][team1[j]] + cost[team1[j]][team1[i]];
			}
		}
		for (int i = 0; i < team2.size() - 1; i++) {
			for (int j = i + 1; j < team2.size(); j++) {
				team2_sum += cost[team2[i]][team2[j]] + cost[team2[j]][team2[i]];
			}
		}
		ans = min(ans, abs(team1_sum - team2_sum));
		return;
	}
	for (int i = idx; i <= n; i++) {
		visit[i] = true;
		combi(i + 1, cnt + 1, end_cnt);
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n / 2; i++) {
		combi(1, 0, i);
	}
	cout << ans;
}