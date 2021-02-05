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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int a, b;
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		cin >> a >> b;
		int l = 0;
		for (int i = 1; i <= min(a, b); i++) {
			if (a % i == 0 && b % i == 0) {
				l = i;
			}
		}
		cout << (a * b) / l <<' '<< l << '\n';
	}
	//print

}