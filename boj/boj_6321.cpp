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
string s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		cin >> s;
		cout << "String #" << i << '\n';
		for (int j = 0; j < (int)s.length(); j++) {
			if (s[j] + 1 > 'Z')s[j] = 'A';
			else s[j] = s[j] + 1;
			cout << s[j];
		}cout << "\n\n";
	}
}