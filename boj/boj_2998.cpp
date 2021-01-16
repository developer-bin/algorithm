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
int convert(string ss) {
	if (ss == "000")return 0;
	if (ss == "001")return 1;
	if (ss == "010")return 2;
	if (ss == "011")return 3;
	if (ss == "100")return 4;
	if (ss == "101")return 5;
	if (ss == "110")return 6;
	if (ss == "111")return 7;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	if ((int)s.length() % 3 != 0) {
		int n = 3 - (int)s.length() % 3;
		for (int i = 1; i <= n; i++) {
			s.insert(0, "0");
		}
	}
	//print
	string ss;
	for (int i = 0; i < (int)s.length(); i++) {
		if ((int)ss.length() == 3) {
			cout<<convert(ss);
			ss.clear();
		}
		ss += s[i];
	}
	if ((int)ss.length() == 3) {
		cout << convert(ss);
	}
	return 0;
}