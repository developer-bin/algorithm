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
int a[301];
int d[301][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	d[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		d[i][2] = d[i - 1][1] + a[i];
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + a[i];
	}
	//print
	cout << max(d[n][1], d[n][2]);
}