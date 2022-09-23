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
int n;
char maps[101][101];
int row_cnt;
int col_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (maps[i][j] == 'X') {
				if (cnt >= 2) {
					row_cnt += 1;
				}
				cnt = 0;
			}
			else {
				cnt += 1;
			}
		}
		if (cnt >= 2)row_cnt += 1;
	}
	for (int j = 1; j <= n; j++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (maps[i][j] == 'X') {
				if (cnt >= 2) {
					col_cnt += 1;
				}
				cnt = 0;
			}
			else {
				cnt += 1;
			}
		}
		if (cnt >= 2)col_cnt += 1;
	}
	//print
	cout << row_cnt << ' ' << col_cnt;
	return 0;
}
