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
vector<string> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	int s_len = (int)s.length();
	for (int i = 0; i < s_len; i++) {
		v.push_back(s.substr(i));
	}
	sort(v.begin(), v.end());
	for (string k : v) {
		cout << k << '\n';
	}
}