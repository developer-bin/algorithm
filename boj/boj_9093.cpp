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
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	cin.ignore();
	//solve
	while (t--) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string tmp;
		while (getline(ss, tmp, ' ')) {
			reverse(tmp.begin(), tmp.end());
			cout << tmp << ' ';
		}cout << '\n';
	}
	//print
	return 0;
}