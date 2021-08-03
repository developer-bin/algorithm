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
int a[1000001];
int b, c;
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	for (int i = 1; i <= n; i++) {
		ans += 1;
		a[i] -= b;
		if (a[i] < 0)continue;
		ans += (a[i] / c);
		if (a[i] % c != 0)ans += 1;
	}

	cout << ans;
}