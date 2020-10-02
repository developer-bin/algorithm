#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
bool number[10];
int ans;
pair<bool,int> checking(int num) {
	int mok=num;
	int cnt = 0;
	while (true) {
		int na = mok % 10;
		mok = mok / 10;
		cnt += 1;
		if (number[na] == false) {
			return { false,-1 };
		}
		if (mok == 0)break;
	}
	return { true,cnt };
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(number, true, sizeof(number));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		number[num] = false;
	}
	ans = abs(n - 100);
	for (int i = 0; i <= 1000000; i++) {
		auto result=checking(i);
		bool check = result.first;
		int num_cnt = result.second;
		if (check) {
			ans = min(ans, abs(n - i) + num_cnt);
		}
	}
	cout << ans;
}