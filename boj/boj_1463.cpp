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
int n;
int d[1000001];
int f(int num) {
	if (num < 1)return MAX_VALUE;
	if (num == 1) { return 0; }
	int &ans = d[num];
	if (ans != -1)return ans;
	ans = MAX_VALUE;
	if (num % 3 == 0)ans=min(ans, f(num / 3) + 1);
	if (num % 2 == 0)ans=min(ans, f(num / 2) + 1);
	ans=min(ans, f(num - 1) + 1);
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve print
	cout << f(n);
}