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
string from, to;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	while (n--) {
		int from_check[26],to_check[26];
		bool check = true;
		memset(from_check, 0, sizeof(from_check));
		memset(to_check, 0, sizeof(to_check));
		cin >> from >> to;
		for (int i = 0; i < (int)from.length(); i++) {
			from_check[from[i] - 'a'] += 1;
		}
		for (int i = 0; i < (int)to.length(); i++) {
			to_check[to[i] - 'a'] += 1;
		}
		for (int i = 0; i < 26; i++) {
			if (from_check[i] != to_check[i]) {
				check = false;
				break;
			}
		}
		if (check)cout << "Possible\n";
		else cout << "Impossible\n";
	}
}