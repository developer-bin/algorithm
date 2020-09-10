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
int n;
stack<pair<int, int>> st;//³ôÀÌ idx
int ans;
void solve(int num,int idx) {
	if (st.empty()) {
		st.push({ num,idx });
		return;
	}
	while(st.empty()==false && st.top().first > num) {
		pair<int, int> now = st.top();
		st.pop();
		int width=0;
		if (st.empty()) {
			width = idx - 1;
		}
		else {
			width = idx - 1 - st.top().second;
		}
		int height = now.first;
		ans = max(ans, width*height);
	}
	st.push({ num,idx });
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		solve(num,i);
	}
	solve(0, n + 1);
	//solve
	//print
	cout << ans;
	return 0;
}