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
string cmp_s;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, s);
	getline(cin, cmp_s);

	for (int i = 0; i < (int)s.length(); i++) {
		string slice_s = s.substr(i, (int)cmp_s.length());
		if (slice_s == cmp_s) {
			cnt += 1; 
			i += (int)cmp_s.length()-1;
		}
	}

	cout << cnt;
}