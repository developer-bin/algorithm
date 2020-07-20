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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int a[14], k;
bool combi_check[14];
void combi(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 1; i <= k; i++) {
			if (combi_check[i])cout << a[i] << ' ';
		}cout << '\n';
	}
	for (int i = idx; i <= k; i++) {
		combi_check[i] = true;
		combi(i + 1, cnt + 1);
		combi_check[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	while (true) {
		cin >> k;
		if (k == 0)break;
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
		}
		//solve
		combi(1, 0);
		cout << '\n';
	}
}