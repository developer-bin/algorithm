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

ll a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> a >> b >> c >> d;
		if (a == 0 && b == 0 && c == 0 && d == 0)break;

		int cnt = 0;
		while (!(a == b && a == c && a == d && b == c && b == d && c == d)) {
			ll ca, cb, cc, cd;
			ca = abs(a - b);
			cb = abs(b - c);
			cc = abs(c - d);
			cd = abs(d - a);

			a = ca;
			b = cb;
			c = cc;
			d = cd;

			cnt += 1;
		}

		cout << cnt << '\n';
	}
}