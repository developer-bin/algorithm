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

int a, b;
string s;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> a >> s >> b;

		if (s == "E")break;

		cout << "Case " << ++cnt << ": ";
		if (s == ">") {
			if (a > b)cout << "true\n";
			else cout << "false\n";
		}
		else if (s == ">=") {
			if (a >= b)cout << "true\n";
			else cout << "false\n";
		}
		else if (s == "<") {
			if (a < b)cout << "true\n";
			else cout << "false\n";
		}
		else if (s == "<=") {
			if (a <= b)cout << "true\n";
			else cout << "false\n";
		}
		else if (s == "==") {
			if (a == b)cout << "true\n";
			else cout << "false\n";
		}
		else if (s == "!=") {
			if (a != b)cout << "true\n";
			else cout << "false\n";
		}
	}
}