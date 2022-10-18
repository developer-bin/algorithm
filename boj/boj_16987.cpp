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
int n;
int negudo[9];
int weight[9];
int ans = 0;

void dfs(int idx,int cnt) {
	if (idx == n + 1) {
		ans = max(ans, cnt);
		return;
	}
	if (negudo[idx] <= 0) { 
		dfs(idx + 1, cnt); 
	}
	else {
		bool check = false;
		for (int i = 1; i <= n; i++) {
			if (i == idx)continue;
			if (negudo[idx] >= 1 && negudo[i] >= 1) {
				check = true;
				negudo[idx] -= weight[i];
				negudo[i] -= weight[idx];
				int broke = 0;
				if (negudo[idx] <= 0)broke += 1;
				if (negudo[i] <= 0)broke += 1;
				dfs(idx + 1, cnt + broke);
				negudo[idx] += weight[i];
				negudo[i] += weight[idx];
			}
		}
		if (check == false)dfs(idx + 1, cnt);
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
		cin >> negudo[i] >> weight[i];
	}
	//solve
	dfs(1,0);
	cout << ans;
}
