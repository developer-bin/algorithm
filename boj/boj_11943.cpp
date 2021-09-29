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

int a, b, c, d;
int ans = MAX_VALUE;

void state(int u_a, int u_b, int d_a, int d_b, int cnt, int sum) {
	if (cnt == 1) {
		ans = min(ans, sum);
		return;
	}

	state(0, u_b + d_b, u_a + d_a, 0, cnt + 1, u_a + d_b);
	state(u_a + d_a, 0, 0, u_b + d_b, cnt + 1, u_b + d_a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c >> d;

	state(a, b, c, d, 0, 0);

	cout << ans;
}