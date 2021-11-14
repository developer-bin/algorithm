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
string l;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;

	string s = "1";
	while (n--) {
		bool check = true;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == l[0]) {
				check = false;
				break;
			}
		}

		s = to_string(stoi(s) + 1);

		if (check == false)n += 1;
	}

	cout << stoi(s) - 1;
}