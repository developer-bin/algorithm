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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int t;
int n, m;
int ans;
int d[31][31];
int combi(int idx, int cnt) {
	if (cnt == n) {
		return 1;
	}
	int &ans = d[idx][cnt];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = idx; i <= m; i++) {
		ans+=combi(i + 1, cnt + 1);
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		cin >> n >> m;
		cout<<combi(1,0)<<'\n';
	}
	//solve
	//print
}