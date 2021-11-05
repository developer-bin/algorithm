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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (int i = 0; i < (int)s.length(); i++) {
		int c = s[i];
		string tmp_s=to_string(c);
		int sum = 0;
		
		for (int j = 0; j < (int)tmp_s.length(); j++) {
			sum += (tmp_s[j] - '0');
		}

		for (int j = 0; j < sum; j++) {
			cout << s[i];
		}cout << '\n';
	}
}