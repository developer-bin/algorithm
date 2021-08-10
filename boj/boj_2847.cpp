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
int a[101];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = n; i >= 2; i--) {
		if (a[i - 1] >= a[i]) {
			ans += (a[i - 1] - a[i] + 1);
			a[i - 1] = a[i - 1] - (a[i - 1] - a[i] + 1);
		}
	}

	cout << ans;
}