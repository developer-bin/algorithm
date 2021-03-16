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
int a[11];
int cnt[1001];
int max_num = MIN_VALUE;
int max_diff = MIN_VALUE;
int avg;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
		avg += a[i];
		cnt[a[i]] += 1;
	}
	//solve
	for (int i = 1; i <= 1000; i++) {
		if (max_diff < cnt[i]) {
			max_diff = cnt[i];
			max_num = i;
		}
	}
	//print
	cout << avg / 10 << '\n' << max_num;
}