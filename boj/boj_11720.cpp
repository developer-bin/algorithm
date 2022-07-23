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
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		ans += (s[i] - '0');
	}
	//print
	cout << ans;
	return 0;
}
