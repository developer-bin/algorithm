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
int cnt[42];
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 10; i++) {
		int num;
		cin >> num;
		cnt[num % 42] += 1;
	}
	//solve
	for (int i = 0; i < 42; i++) {
		if (cnt[i] != 0)ans += 1;
	}
	//print
	cout << ans;
}