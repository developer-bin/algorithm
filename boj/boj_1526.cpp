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

bool checking(int num) {
	string s = to_string(num);
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] != '7' && s[i] != '4') {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = n; i >= 1; i--) {
		if (checking(i)) {
			cout << i;
			return 0;
		}
	}
	//print
	return 0;
}