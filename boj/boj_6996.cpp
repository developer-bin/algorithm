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
int n;
int check1[26], check2[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		memset(check1, 0, sizeof(check1));
		memset(check2, 0, sizeof(check2));
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < (int)s1.length(); j++) {
			check1[s1[j] - 'a'] += 1;
		}
		for (int j = 0; j < (int)s2.length(); j++) {
			check2[s2[j] - 'a'] += 1;
		}
		bool check = true;
		for (int j = 0; j < 26; j++) {
			if (check1[j] != check2[j]) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << s1 << " & " << s2 << " are " << "anagrams.\n";
		}
		else {
			cout << s1 << " & " << s2 << " are " << "NOT anagrams.\n";
		}
	}
}