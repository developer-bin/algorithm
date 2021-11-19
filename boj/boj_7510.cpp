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
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "Scenario #" << i << ":\n";
		
		for (int j = 0; j < 3; j++) {
			cin >> a[j];
		}

		sort(a, a + 3);

		if ((a[0] * a[0] + a[1] * a[1]) == a[2] * a[2])cout << "yes\n";
		else cout << "no\n";

		cout << "\n";
	}
}