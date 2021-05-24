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
bool a[4];
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	a[1] = true;
	//input
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == 'A') {
			swap(a[1], a[2]);
		}
		else if (s[i] == 'B') {
			swap(a[2], a[3]);
		}
		else if (s[i] == 'C') {
			swap(a[1], a[3]);
		}
	}
	//print
	for (int i = 1; i <= 3; i++) {
		if (a[i] == true)cout << i;
	}
}