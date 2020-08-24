#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
ll a, b, c;
ll f(ll a,ll b) {
	if (b == 0)return 1;
	else if (b == 1)return a;
	else if (b % 2 == 0) {
		ll n_a = f(a, b / 2);
		n_a %= c;
		return (n_a*n_a) % c;
	}
	else if (b % 2 == 1) {
		return ((a%c)*(f(a, b - 1) % c)) % c;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> a >> b >> c;
	//solve
	cout << f(a, b) % c;
}