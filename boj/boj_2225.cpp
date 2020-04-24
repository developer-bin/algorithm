#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
ll n, k;
bool visit[201];
ll d[201][201];
ll dfs(int cnt,int sum) {
	if (sum > n)return 0;
	if (cnt == k) {
		if (sum == n) {  return 1; }
		else { return 0; }
	}
	ll &ans = d[cnt][sum];
	if (ans != -1)return ans;
	ans = 0;
	for (int i = 0; i <= n; i++) {
		ans+=dfs(cnt + 1,sum+i)%1000000000;
	}
	return ans%=1000000000;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//init
	//input
	cin >> n >> k;
	//solve print
	cout<<dfs(0, 0);
}