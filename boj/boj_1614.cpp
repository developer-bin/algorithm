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
#define MOD 1000000000
#define ll long long
using namespace std;
int son;
ll cnt;
ll ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//input
	cin >> son >> cnt;
	//solve
	if (2 <= son && son <= 4) {
		ll tmp_cnt = 6 + 4 * (cnt - 1);
		if (cnt % 2 == 0) {
			int tmp_son = 2;
			while (true) {
				if (son == tmp_son) {
					tmp_cnt -= 1;
					break;
				}
				tmp_son += 1;
				tmp_cnt += 1;
			}
			ans = tmp_cnt;
		}
		else {
			int tmp_son = 4;
			while (true) {
				if (son == tmp_son) {
					tmp_cnt -= 1;
					break;
				}
				tmp_son -= 1;
				tmp_cnt += 1;
			}
			ans = tmp_cnt;
		}
	}
	else {
		ll tmp_cnt = 6 + 8 * (cnt - 1);
		int tmp_son = 4;
		bool check = false;
		while (true) {
			if (son == tmp_son) {
				tmp_cnt -= 1;
				break;
			}
			if (check == false) {
				tmp_son -= 1;
			}
			else if (check) {
				tmp_son += 1;
			}
			tmp_cnt += 1;
			if (tmp_son == 0) {
				tmp_son = 2;
				check = true;
			}
		}
		ans = tmp_cnt;
	}
	//print
	cout << ans;
}