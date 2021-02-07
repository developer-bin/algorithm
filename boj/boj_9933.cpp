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
vector<string> v;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	//solve
	for (int i = 0; i < v.size() - 1; i++) {
		string a=v[i];
		for (int j = i + 1; j < v.size(); j++) {
			string b = v[j];
			reverse(b.begin(), b.end());
			if (a == b) {
				cout << (int)a.length()<<' '<<a[(int)a.length()/2];
				return 0;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		string a = v[i];
		string b = v[i];
		reverse(b.begin(), b.end());
		if (a == b) {
			cout << (int)a.length() << ' ' << a[(int)a.length() / 2];
			return 0;
		}
	}
	//print
	return 0;
}