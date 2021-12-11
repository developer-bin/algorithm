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
int start, endd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> s;

	start = 0;
	endd = (int)s.length() - 1;

	while (start <= endd) {
		if (s[start] == '?' && s[endd] != '?') {

			s[start] = s[endd];

		}
		else if (s[start] != '?' && s[endd] == '?') {

			s[endd] = s[start];

		}
		else if (s[start] == '?' && s[endd] == '?') {

			s[start] = s[endd] = 'a';

		}

		start += 1;
		endd -= 1;
	}

	cout << s;
}