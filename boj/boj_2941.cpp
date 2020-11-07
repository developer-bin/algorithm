#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
string s;
map<string, bool> maps = { {"c=",true},{"c-",true},{"dz=",true},{"d-",true},{"lj",true},{"nj",true},{"s=",true},{"z=",true} };
int main() {
	cin >> s;
	int s_len = s.length();
	int cnt = 0;
	for (int i = 0; i < s_len; i++) {
		if (i + 1 < s_len) {
			string ss = s.substr(i, 2);
			if (maps.count(ss)) {
				cnt += 1;
				i += 1;
				continue;
			}
		}
		if (i + 2 < s_len) {
			string ss = s.substr(i, 3);
			if (maps.count(ss)) {
				cnt += 1;
				i += 2;
				continue;
			}
		}
		cnt += 1;
	}
	cout << cnt;
}