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
int n, m;
bool visit[9];
int a[9];
vector<int> permu_v;
void permu(int cnt) {
	if (cnt == m) {
		for (int k : permu_v) {
			cout << k << ' ';
		}cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		permu_v.push_back(a[i]);
		permu(cnt + 1);
		permu_v.pop_back();
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	sort(a + 1, a + n + 1);
	permu(0);
}