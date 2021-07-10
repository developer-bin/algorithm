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
int n;
char maps[51][6][8];
int ans_a, ans_b;
int min_cnt = MAX_VALUE;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	int idx = 1;
	while (n--) {
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 7; j++) {
				cin >> maps[idx][i][j];
			}
		}
		idx += 1;
	}
	idx -= 1;
	//solve
	for (int i = 1; i <= idx - 1; i++) {
		for (int j = i + 1; j <= idx; j++) {
			int cnt = 0;
			for (int a = 1; a <= 5; a++) {
				for (int b = 1; b <= 7; b++) {
					if (maps[i][a][b] != maps[j][a][b]) cnt += 1;
				}
			}
			if (cnt < min_cnt) {
				min_cnt = cnt;
				ans_a = i;
				ans_b = j;
			}
		}
	}
	cout << ans_a << ' ' << ans_b;
}