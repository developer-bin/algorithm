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

int n;
int m;
int a[15001];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] + a[j] == m)ans += 1;
		}
	}

	cout << ans;
}