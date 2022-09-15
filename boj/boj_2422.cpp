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
int n, m;
bool no[201][201];
int ans;
int combi_a[10];

void combi(int idx, int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < 2; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (no[combi_a[i]][combi_a[j]])return;
			}
		}
		ans += 1;
		return;
	}
	for (int i = idx; i <= n; i++) {
		combi_a[cnt] = i;
		combi(i + 1, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int ice1, ice2;
		cin >> ice1 >> ice2;
		no[ice1][ice2] = true;
		no[ice2][ice1] = true;
	}
	//solve
	combi(1, 0);
	cout << ans;
}
