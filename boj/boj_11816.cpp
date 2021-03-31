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
string sub_s;
int ans;
int num = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	if (s.length() >= 2 && s[0] == '0' && s[1] == 'x') {
		sub_s = s.substr(2);
		reverse(sub_s.begin(), sub_s.end());
		for (int i = 0; i < (int)sub_s.length(); i++) {
			if ('a' <= sub_s[i] && sub_s[i] <= 'f') {
				ans += ((sub_s[i] - 'a') + 10)*num;
			}
			else {
				ans += (sub_s[i] - '0') * num;
			}
			num *= 16;
		}
		cout << ans;
	}
	else if (s.length() >= 2 && s[0] == '0') {
		sub_s = s.substr(1);
		reverse(sub_s.begin(), sub_s.end());
		for (int i = 0; i < (int)sub_s.length(); i++) {
			ans += (sub_s[i] - '0') * num;
			num *= 8;
		}
		cout << ans;
	}
	else {
		cout << s;
	}
	//print
}