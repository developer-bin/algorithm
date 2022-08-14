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
int n, m;
vector<string> s1;
vector<string> s2;
vector<string> s3;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> m;
	//solve
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		s1.push_back(s);
		string ss;
		for (int i = 0; i < (int)s.length(); i++) {
			ss += s[i];
			ss += s[i];
		}
		s3.push_back(ss);
	}
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		s2.push_back(s);
	}
	bool check = true;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] != s3[i]) {
			check = false;
			break;
		}
	}
	if (check)cout << "Eyfa";
	else cout << "Not Eyfa";
}
