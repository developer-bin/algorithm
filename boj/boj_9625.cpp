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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int k;
int a_cnt=1, b_cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> k;
	//solve
	for (int i = 1; i <= k; i++) {
		int before_a_cnt = a_cnt, before_b_cnt = b_cnt;
		a_cnt = 0;
		b_cnt = 0;
		a_cnt += before_b_cnt;
		b_cnt += (before_a_cnt + before_b_cnt);
	}
	//print
	cout << a_cnt << ' ' << b_cnt;
}
