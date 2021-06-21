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
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		string s1, s2;
		cin >> s2;
		s1 = s2;
		reverse(s2.begin(), s2.end());
		string s3 = to_string(stoi(s1) + stoi(s2));
		string s4 = s3;
		reverse(s3.begin(), s3.end());
		if (s3 == s4)cout << "YES\n";
		else cout << "NO\n";
	}
}