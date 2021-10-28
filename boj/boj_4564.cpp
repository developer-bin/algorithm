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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int n;
		cin >> n;
		
		if (n == 0)break;

		while (n >= 10) {
			cout << n << ' ';

			string s = to_string(n);
			int num = 1;

			for (int i = 0; i < (int)s.length(); i++) {
				num = num * (s[i] - '0');
			}

			n = num;
		}

		cout << n << '\n';
	}
}