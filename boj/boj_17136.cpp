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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int maps[10][10];
int ans = MAX_VALUE;
bool visit[10][10];
int paper_cnt[6];
bool checking(int x, int y,int area) {
	for (int i = x; i < x + area; i++) {
		for (int j = y; j < y + area; j++) {
			if (i >= 10 || j >= 10)return false;
			if (maps[i][j] == 0)return false;
			if (visit[i][j])return false;
		}
	}
	return true;
}
void attach(int x, int y, int area) {
	for (int i = x; i < x + area; i++) {
		for (int j = y; j < y + area; j++) {
			visit[i][j] = true;
		}
	}
}
void unattach(int x, int y, int area) {
	for (int i = x; i < x + area; i++) {
		for (int j = y; j < y + area; j++) {
			visit[i][j] = false;
		}
	}
}
bool all_attach_checking() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (maps[i][j] == 1 && visit[i][j]==false) {
				return false;
			}
		}
	}
	return true;
}
void state(int n,int cnt) {
	if (n == 100) {
		if (all_attach_checking()) {
			ans = min(ans, cnt);
		}
		return;
	}
	int x = n / 10;
	int y = n % 10;
	bool check=true;
	for (int i = 1; i <= 5; i++) {
		if (paper_cnt[i] == 0)continue;
		if (checking(x, y, i)) {
			attach(x, y, i);
			paper_cnt[i] -= 1;
			state(n + 1, cnt + 1);
			unattach(x, y, i);
			paper_cnt[i] += 1;
			check = false;
		}
	}
	if (check)state(n + 1, cnt);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> maps[i][j];
		}
	}
	//solve
	for (int i = 1; i <= 5; i++)paper_cnt[i] = 5;
	state(0,0);
	//print
	if (ans == MAX_VALUE) cout << -1;
	else cout << ans;
}