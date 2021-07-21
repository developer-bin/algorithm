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
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, m;
int a[100001];
int ans = MAX_VALUE;
bool checking(int m) {
	int sum = 0;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		if (a[i] > m)return false;
		sum += a[i];
		if (sum > m) {
			sum -= a[i];
			v.push_back(sum);
			sum = 0;
			i -= 1;
		}
	}
	if (v.size()+1 > ::m)return false;
	else return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int s = 1, e = 1000000000;
	while (s <= e) {
		int m = (s + e) / 2;
		if (checking(m)) {
			e = m - 1;
			ans = min(ans, m);
		}
		else {
			s = m + 1;
		}
	}
	cout << ans;
}