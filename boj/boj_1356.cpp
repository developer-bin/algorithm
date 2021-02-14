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
bool check;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	for (int cnt = 1; cnt <= (int)s.length() - 1; cnt++) {
		string s1 = s.substr(0, cnt);
		string s2 = s.substr(cnt);
		int mul1 = 1, mul2 = 1;
		for (int i = 0; i < (int)s1.length(); i++) {
			mul1 *= (s1[i] - '0');
		}
		for (int i = 0; i < (int)s2.length(); i++) {
			mul2 *= (s2[i] - '0');
		}
		if (mul1 == mul2) {
			check = true;
			break;
		}
	}
	if (check) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}