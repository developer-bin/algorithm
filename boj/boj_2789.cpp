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
bool check[26];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	check['C' - 'A'] = true;
	check['A' - 'A'] = true;
	check['M' - 'A'] = true;
	check['B' - 'A'] = true;
	check['R' - 'A'] = true;
	check['I' - 'A'] = true;
	check['D' - 'A'] = true;
	check['G' - 'A'] = true;
	check['E' - 'A'] = true;
	//input
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (check[s[i] - 'A'] == true) {
			continue;
		}
		cout << s[i];
	}
	//print
}