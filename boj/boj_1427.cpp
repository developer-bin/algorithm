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
string s;
int cnt[10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		cnt[s[i] - '0'] += 1;
	}
	//print
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i;
		}
	}
}