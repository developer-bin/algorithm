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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
bool eratos[3000001];
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	eratos[1] = true;
	for (int i = 2; i <= 3000000; i++) {
		if (eratos[i] == false) {
			for (int j = i + i; j <= 3000000; j += i)eratos[j] = true;
		}
	}
	//input
	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;
		int ans = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (eratos[i] == false)ans += 1;
		}
		cout << ans << '\n';
	}
	//solve
	//print
}