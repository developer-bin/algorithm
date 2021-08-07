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
char a[51][51];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = MIN_VALUE;

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}

int row_checking(int x, int y) {
	char start_c = a[x][y];
	int cnt = 0;

	for (int j = y; j <= n; j++) {
		if (start_c == a[x][j])cnt += 1;
		else break;
	}

	return cnt;
}

int col_checking(int x, int y) {
	char start_c = a[x][y];
	int cnt = 0;

	for (int i = x; i <= n; i++) {
		if (start_c == a[i][y])cnt += 1;
		else break;
	}

	return cnt;
}

void checking() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans=max(ans,row_checking(i, j));
			ans=max(ans,col_checking(i, j));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (boundary(nx, ny)) {
					swap(a[i][j], a[nx][ny]);
					checking();
					swap(a[i][j], a[nx][ny]);
				}
			}
		}
	}

	cout << ans;
}