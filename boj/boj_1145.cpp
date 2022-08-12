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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int a[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 5; i++) {
		cin >> a[i];
	}
	//solve
	int ans = 1;
	while (true) {
		int cnt = 0;
		for (int i = 1; i <= 5; i++) {
			if (ans % a[i] == 0)cnt += 1;
		}
		if (cnt >= 3) {
			cout << ans;
			break;
		}
		ans += 1;
	}
	//print
}
