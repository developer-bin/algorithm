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

int w, h;
char maps[101][101];
int ans[101][101];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> w >> h;
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cin >> maps[i][j];
		}
	}

	for (int i = 1; i <= w; i++) {
		int cnt = 0;

		for (int j = 1; j <= h; j++) {
			if (maps[i][j] == '.' && cnt == 0)ans[i][j] = -1;
			else if (maps[i][j] == 'c') {
				cnt = 1;
				ans[i][j] = 0;
			}
			else if (maps[i][j] == '.' && cnt >= 1) {
				ans[i][j] = cnt++;
			}
		}
	}

	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			cout << ans[i][j] << ' ';
		}cout << '\n';
	}
}