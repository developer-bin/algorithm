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

int h, m;
int times;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> m;

	times = h * 60 + m - 45;

	if (times < 0) {
		times += 60;
		cout << 23 << ' ' << times;
	}
	else cout << times / 60 << ' ' << times % 60;
}