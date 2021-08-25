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

string s1, s2;
int tc=1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> s1 >> s2;
		
		if (s1 == "END" && s2 == "END")break;

		int s1_cnt[26];
		int s2_cnt[26];
		memset(s1_cnt, 0, sizeof(s1_cnt));
		memset(s2_cnt, 0, sizeof(s2_cnt));

		for (int i = 0; i < (int)s1.length(); i++) {
			s1_cnt[s1[i] - 'a'] += 1;
		}

		for (int i = 0; i < (int)s2.length(); i++) {
			s2_cnt[s2[i] - 'a'] += 1;
		}

		bool check = true;
		for (int i = 0; i < 26; i++) {
			if (s1_cnt[i] != s2_cnt[i]) {
				check = false;
				break;
			}
		}

		if (check == true) {
			cout << "Case " << tc++ << ": same\n";
		}
		else {
			cout << "Case " << tc++ << ": different\n";
		}
	}
}