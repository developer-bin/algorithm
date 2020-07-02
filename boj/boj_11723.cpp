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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int s, n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	while (n--) {
		string str;
		int x;
		cin >> str;
		if (str == "add") {
			cin >> x;
			s = s | (1 << x);
		}
		else if (str == "remove") {
			cin >> x;
			s = s & ~(1 << x);
		}
		else if (str == "check") {
			cin >> x;
			if (s&(1 << x))cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		else if (str == "toggle") {
			cin >> x;
			if (s&(1 << x)) {
				s = s & ~(1 << x);
			}
			else {
				s = s | (1 << x);
			}
		}
		else if (str == "all") {
			s = 0;
			s = s | (1 << 21);
			s -= 1;
		}
		else if (str == "empty") {
			s = 0;
		}
	}
	//solve
}