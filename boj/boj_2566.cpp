#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int ans = MIN_VALUE;
int x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int num;
			cin >> num;
			if (ans < num) {
				ans = num;
				x = i;
				y = j;
			}
		}
	}
	//solve
	cout << ans << '\n' << x << ' ' << y;
}