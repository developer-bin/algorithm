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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
int d[21];
int solve(int n) {
	if (n == 0)return d[n]=0;
	if (n == 1)return d[n]=1;
	int& ans = d[n];
	if (ans != -1)return ans;
	ans = 0;
	return ans = solve(n - 1) + solve(n - 2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve
	cout << solve(n);
	return 0;
}