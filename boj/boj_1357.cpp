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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
string x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> x >> y;
	//solve
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	string s = to_string(stoi(x) + stoi(y));
	reverse(s.begin(), s.end());
	//print
	cout << stoi(s);
}