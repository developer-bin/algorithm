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

int t, n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> n;

		char c1, c2;
		int c1_cnt = 0, c2_cnt = 0;

		cin.ignore();

		while (n--) {
			cin >> c1;
			cin.ignore();

			cin >> c2;
			cin.ignore();

			if (c1 == 'R' && c2 == 'S') {
				c1_cnt += 1;
			}
			else if (c1 == 'P' && c2 == 'R') {
				c1_cnt += 1;
			}
			else if (c1 == 'S' && c2 == 'P') {
				c1_cnt += 1;
			}
			else if (c1 == c2) {
				continue;
			}
			else {
				c2_cnt += 1;
			}
		}

		if (c1_cnt > c2_cnt) {
			cout << "Player 1\n";
		}
		else if (c1_cnt < c2_cnt) {
			cout << "Player 2\n";
		}
		else cout << "TIE\n";
	}
}