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
string s;
int n;
int ans;
int exp_num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s >> n;
	//solve
	for (int i = (int)s.length() - 1; i >= 0; i--) {
		int num = 0;
		if ('A' <= s[i] && s[i] <= 'Z') {
			num = (s[i] - 'A') + 10;
		}
		else {
			num = s[i] - '0';
		}
		ans+=(num*(int)pow(n, exp_num));
		exp_num += 1;
	}
	//print
	cout << ans;
	return 0;
}