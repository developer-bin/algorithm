#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int t, a, b;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int tmp_a, tmp_b;
		cin >> tmp_a >> tmp_b;
		a = max(tmp_a, tmp_b);
		b = min(tmp_a, tmp_b);
		cout << a * b / gcd(a, b)<<'\n';
	}
	//print
}
