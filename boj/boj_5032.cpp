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

int e, f, c;
int ans;

void state(int bottle, int sum) {
	if (bottle / c == 0) {
		ans = sum;
		return;
	}

	int new_bottle = bottle / c;
	sum += new_bottle;

	state(new_bottle + bottle % c, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> e >> f >> c;

	state(e+f, 0);

	cout << ans;
}