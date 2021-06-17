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
string s;
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		cin >> s;
		bool alpha[26];
		int sum = 0;
		memset(alpha, false, sizeof(alpha));
		for (int i = 0; i < (int)s.length(); i++) {
			alpha[s[i] - 'A'] = true;
		}
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == false) {
				sum += 'A' + i;
			}
		}
		cout << sum << '\n';
	}
	//print
}