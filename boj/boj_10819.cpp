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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
int a[9];
bool visit[9];
vector<int> v;
int ans = MIN_VALUE;

void permu(int cnt) {
	if (cnt == n) {
		int sum = 0;
		for (int i = 0; i < v.size()-1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}
		ans = max(sum, ans);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			v.push_back(a[i]);
			permu(cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	permu(0);
	cout << ans;
}