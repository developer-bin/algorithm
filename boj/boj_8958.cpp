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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int ans = 0;
		int o_cnt = 0;
		for (int j = 0; j < (int)s.length(); j++) {
			if (s[j] == 'O') {
				o_cnt += 1;
				ans += o_cnt;
			}
			else if (s[j] != 'O') {
				o_cnt = 0;
			}
		}
		cout << ans << '\n';
	}
	//print
	return 0;
}