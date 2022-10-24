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
string s;
int zero_cnt, one_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> s;
	//solve
	if (s.length() == 0) {
		cout << 0;
	}
	else {
		if (s[0] == '0') {
			zero_cnt += 1;
		}
		else one_cnt += 1;
		for (int i = 1; i < (int)s.length(); i++) {
			if (s[i] != s[i - 1]) {
				if (s[i] == '0') {
					zero_cnt += 1;
				}
				else one_cnt += 1;
			}
		}
	}
	//print
	cout << min(zero_cnt, one_cnt);
}
