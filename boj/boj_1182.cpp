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
int n, s;
int a[21];
bool visit[2000001];
int ans;
void combi(int idx, int sum,int &cnt,int now_cnt) {
	if (now_cnt == cnt && sum==s) {
		ans += 1;
		return;
	}
	for (int i = idx; i <= n; i++) {
		combi(i + 1, sum + a[i], cnt,now_cnt+1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> s;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	for (int i = 1; i <= n; i++) {
		combi(1, 0, i,0);
	}
	cout << ans;
}