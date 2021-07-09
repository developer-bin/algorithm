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
vector<int> v;
int a, b;
int sum[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> a >> b;
	a -= 2;
	b -= 1;
	//solve
	int diff = 2;
	int idx = 1;
	sum[0] = 1;
	while (true) {
		for (int i = 1; i <= diff; i++) {
			sum[idx] = sum[idx - 1] + diff;
			idx += 1;
			if (idx >= 1000)break;
		}
		if (idx >= 1000)break;
		diff += 1;
	}
	if (a < 0) {
		cout << sum[b];
	}
	else cout << sum[b] - sum[a];
}