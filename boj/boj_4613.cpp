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

	while (true) {
		getline(cin, s);
		if (s == "#")break;

		int sum = 0;
		int cnt = 1;

		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == ' ') {
				cnt++;
				continue;

			}

			sum += (cnt++ * (s[i] - 'A' + 1));
		}

		cout << sum << '\n';
	}
}