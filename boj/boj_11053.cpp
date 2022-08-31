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
int a[1001];
int d[1001];

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
	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				d[i] = max(d[j] + 1, d[i]);
			}
		}
	}
	//print
	cout << *max_element(d + 1, d + 1 + n);
}
