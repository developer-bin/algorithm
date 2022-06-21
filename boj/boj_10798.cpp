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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
string s[6];
int max_col = MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 5; i++) {
		cin >> s[i];
		max_col = max((int)s[i].length(), max_col);
	}
	//solve
	for (int j = 0; j < max_col; j++) {
		for (int i = 1; i <= 5; i++) {
			if ((int)s[i].length() <= j)continue;
			cout << s[i][j];
		}
	}
	//print
}
