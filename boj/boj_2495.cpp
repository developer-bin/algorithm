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
int cnt[10];
int max_cnt[10];
int ans=MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 3; i++) {
		for (int i = 0; i < 10; i++) {
			max_cnt[i] = MIN_VALUE;
			cnt[i] = 0;
			ans = MIN_VALUE;
		}
		string num;
		cin >> num;
		cnt[num[0] - '0'] += 1;
		for (int i = 1; i < (int)num.length(); i++) {
			if (num[i - 1] == num[i]) {
				cnt[num[i] - '0'] += 1;
			}
			else {
				max_cnt[num[i-1] - '0'] = max(max_cnt[num[i-1] - '0'], cnt[num[i-1] - '0']);
				cnt[num[i] - '0'] = 1;
			}
		}
		max_cnt[num[(int)num.length()-1] - '0'] = max(max_cnt[num[(int)num.length() - 1] - '0'], cnt[num[(int)num.length() - 1] - '0']);
		for (int i = 0; i < 10; i++) {
			ans = max(ans, max_cnt[i]);
		}
		cout << ans<<'\n';
	}
	//solve
	//print
}
