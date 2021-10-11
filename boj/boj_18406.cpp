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
int l_num;
int r_num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	for (int i = 0; i < (int)s.length() / 2; i++) {
		l_num += (s[i] - '0');
	}

	for (int i = (int)s.length() - 1; i >= (int)s.length() / 2; i--) {
		r_num += (s[i] - '0');
	}

	if (l_num == r_num)cout << "LUCKY";
	else cout << "READY";
}