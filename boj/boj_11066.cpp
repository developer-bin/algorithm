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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int t;
int k;
int a[501];
int sum[501];
int d[501][501];

int state(int left, int right) {
	if (left == right)return 0;
	int &result = d[left][right];
	if (result != -1)return result;
	result = MAX_VALUE;
	for (int i = left; i <= right; i++) {
		result = min(result, state(left, i) + state(i + 1, right) + sum[right] - sum[left - 1]);
	}
	return result;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		memset(d, -1, sizeof(d));
		memset(sum, 0, sizeof(sum));
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		cout << state(1, k)<<'\n';
	}
}