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
int cnt[26];
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		cnt[s[i] - 'a'] += 1;
	}
	//print
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
	return 0;
}