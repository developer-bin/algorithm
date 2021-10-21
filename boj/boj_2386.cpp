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
char c;
map<char, int> maps;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		maps.clear();
		cin >> c;

		if (c == '#')break;

		cin.ignore();
		getline(cin, s);

		c = tolower(c);

		for (int i = 0; i < (int)s.length(); i++) {
			s[i] = tolower(s[i]);
			maps[s[i]] += 1;
		}

		cout << c << ' ' << maps[c] << '\n';
	}
}