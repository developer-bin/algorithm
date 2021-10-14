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
int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		memset(alpha, 0, sizeof(alpha));

		getline(cin, s);

		if (s == "*")break;
		
		for (int i = 0; i < (int)s.length(); i++) {
			alpha[s[i] - 'a'] += 1;
		}

		bool check = true;
		
		for (int i = 0; i < 26; i++) {
			if (alpha[i] == 0)check = false;
		}

		if (check)cout << "Y\n";
		else cout << "N\n";
	}
}