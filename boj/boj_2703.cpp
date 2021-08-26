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

int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin.ignore();
		string s;
		getline(cin, s);
		string key;
		cin >> key;

		for (int i = 0; i < 26; i++) {
			alpha[i] = key[i] - 'A';
		}

		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == ' ')cout << ' ';
			else cout << (char)(alpha[s[i] - 'A']+'A');
		}cout << '\n';
	}
}