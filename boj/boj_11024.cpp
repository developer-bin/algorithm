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
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	cin.ignore();
	while (t--) {
		getline(cin, s);
		stringstream ss(s);
		string tmp_s;
		int ans = 0;
		while (getline(ss,tmp_s, ' ')) {
			ans += stoi(tmp_s);
		}
		cout << ans<<'\n';
	}
	//solve
}