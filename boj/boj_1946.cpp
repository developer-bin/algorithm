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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int t;
int n;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first < b.first)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		sort(v.begin(), v.end());
		int ans = n;
		for (int i = v.size() - 1; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (v[i].second > v[j].second) {
					ans -= 1;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	//solve
	//print
}