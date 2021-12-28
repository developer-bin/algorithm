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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	if ((int)s.length() == 1) {
		cout << "귀요미";
	}
	else {
		bool check = true;
		int d = (s[1] - '0') - (s[0] - '0');
		for (int i = 0; i < (int)s.length() - 1; i++) {
			if ((s[i + 1] - '0') - (s[i] - '0') != d) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << "귀요미";
		}
		else {
			cout << "흠칫뿡";
		}
	}
}