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

	cin >> n;

	while (n--) {
		string s;
		cin >> s;

		int a, b;
		bool check = true;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '+') {
				a = stoi(s.substr(0, i));
				b = stoi(s.substr(i + 1));
				break;
			}
			else if (s[i] == '=') {
				check = false;
				break;
			}
		}

		if (check) {
			cout << a + b << '\n';
		}
		else cout << "skipped\n";
	}
}