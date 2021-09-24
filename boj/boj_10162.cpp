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
int a, b, c;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	if (n >= 5 * 60) {
		a = n / 300;
		n = n % 300;
	}

	if (n >= 60) {
		b = n / 60;
		n = n % 60;
	}

	if (n >= 10) {
		c = n / 10;
		n = n % 10;
	}

	if (n != 0)cout << -1;
	else cout << a << ' ' << b << ' ' << c;
}