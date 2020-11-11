#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string s;
int n;
bool visit[26];
int ans;
int main() {
	cin >> n;
	while (n--) {
		memset(visit, false, sizeof(visit));
		cin >> s;
		int len = s.length();
		bool check = true;
		for (int i = 0; i < len; i++) {
			if (visit[s[i] - 'a'] == false) {
				visit[s[i] - 'a'] = true;
				continue;
			}
			if (visit[s[i] - 'a'] == true && s[i] == s[i - 1])continue;
			if (visit[s[i] - 'a'] == true && s[i] != s[i - 1]) {
				check = false;
				break;
			}
		}
		if (check)ans += 1;
	}
	cout << ans;
}