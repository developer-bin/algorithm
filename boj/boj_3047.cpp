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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
map<string, int> maps;
int a[3];
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	cin >> s;
	//solve
	sort(a, a + 3);
	maps["A"] = a[0];
	maps["B"] = a[1];
	maps["C"] = a[2];
	//print
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == 'A') {
			cout << maps["A"] << ' ';
		}
		else if (s[i] == 'B') {
			cout << maps["B"] << ' ';
		}
		else {
			cout << maps["C"] << ' ';
		}
	}
}