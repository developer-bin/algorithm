#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
int a[10001];
int d[10001][3];
int dfs(int idx, int cnt) {
	if (idx > n)return 0;
	int &result = d[idx][cnt];
	if (result != -1)return result;
	result = 0;
	if (cnt <= 1) {
		result=max(result,dfs(idx + 1, cnt + 1)+a[idx]);
	}
	result=max(result,dfs(idx + 1, 0));
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	//solve
	cout<<dfs(0, 0);
}