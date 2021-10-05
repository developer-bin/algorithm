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

int a[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		for (int i = 0; i < 3; i++) {
			cin >> a[i];
		}

		if (a[0] == 0 && a[1] == 0 && a[2] == 0)break;

		sort(a, a + 3);

		if (a[0] * a[0] + a[1] * a[1] == a[2] * a[2])cout << "right\n";
		else cout << "wrong\n";
	}
}