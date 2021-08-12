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

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	string left = "";
	string right = "";

	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == ':') {
			right = s.substr(i + 1);
			break;
		}
		left += s[i];
	}

	int gcd_num = gcd(stoi(left), stoi(right));
	cout << stoi(left) / gcd_num << ':' << stoi(right) / gcd_num;
}