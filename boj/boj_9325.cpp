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
int t;
int s;
int n;
int p, q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int sum = 0;
		cin >> s;
		cin >> n;
		sum += s;
		for (int i = 1; i <= n; i++) {
			cin >> p >> q;
			sum += (p * q);
		}
		cout << sum << '\n';
	}
	//print
}