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
int t;
int star_diff = 1;
int space_diff = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	t = n;

	while (t--) {
		for (int j = 1; j <= space_diff; j++) {
			cout << ' ';
		}

		for (int j = 1; j <= 2 * n - star_diff; j++) {
			cout << '*';
		}

		cout << '\n';

		space_diff += 1;
		star_diff += 2;
	}
}