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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
char maps[2188][2188];

void state(int n,int x,int y) {
	if (n == 3) {
		for (int i = x; i <= x + 2; i++) {
			for (int j = y; j <= y + 2; j++) {
				if (i == x + 1 && j == y + 1)continue;
				maps[i][j] = '*';
			}
		}
		return;
	}
	state(n / 3, x, y);
	state(n / 3, x, y + n / 3);
	state(n / 3, x, y + 2 * (n / 3));
	state(n / 3, x + (n / 3), y);
	state(n / 3, x + (n / 3), y + 2 * (n / 3));
	state(n / 3, x + 2 * (n / 3), y);
	state(n / 3, x + 2 * (n / 3), y + (n / 3));
	state(n / 3, x + 2 * (n / 3), y + 2 * (n / 3));
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	for (int i = 1; i <= (int)pow(3, 7); i++) {
		for (int j = 1; j <= (int)pow(3, 7); j++) {
			maps[i][j] = ' ';
		}
	}
	//input
	cin >> n;
	//solve
	state(n,1,1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << maps[i][j];
		}cout << '\n';
	}
}