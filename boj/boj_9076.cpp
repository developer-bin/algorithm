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
int a[5];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	while (n--) {
		for (int i = 0; i < 5; i++) {
			cin >> a[i];
		}
		sort(a, a + 5);
		if (abs(a[1] - a[3]) >= 4) {
			cout << "KIN\n";
		}
		else {
			cout << a[1] + a[2] + a[3] << '\n';
		}
	}
	//solve

	//print
}