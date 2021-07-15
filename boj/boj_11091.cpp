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
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		for (int i = 0; i < (int)s.length(); i++) {
			s[i] = tolower(s[i]);
		}
		bool check[26];
		memset(check, false, sizeof(check));
		for (int j = 0; j < (int)s.length(); j++) {
			if ('a' <= s[j] && s[j] <= 'z') {
				check[s[j] - 'a'] = true;
			}
		}
		bool pangram_check = true;
		vector<char> v;
		for (int i = 0; i < 26; i++) {
			if (check[i] == false) {
				pangram_check = false;
				v.push_back('a'+i);
			}
		}
		if (pangram_check) {
			cout << "pangram\n";
		}
		else {
			cout << "missing ";
			for (int i = 0; i < v.size(); i++) {
				cout << v[i];
			}cout << '\n';
		}
	}
}