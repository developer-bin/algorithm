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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
vector<int> v;
int ans = MIN_VALUE;
bool cmp(int a, int b) {
	if (a > b)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//solve
	sort(v.begin(), v.end(),cmp);
	int day = 2;
	for (int i = 0; i < v.size(); i++) {
		ans = max(v[i] + day, ans);
		day += 1;
	}
	//print
	cout << ans;
	return 0;
}