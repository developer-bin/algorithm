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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int t, n;
bool room[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		cin >> n;
		memset(room, false, sizeof(room));
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= n; j += i) {
				if (room[j])room[j] = false;
				else room[j] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (room[i] == false)ans += 1;
		}
		cout << ans << '\n';
	}
}