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
string s;
int result_idx;

pair<int,int> state(int k, int idx, int cnt) {
	if (idx == (int)s.length())return { cnt,0 };//마지막
	if (s[idx] == '(') {
		auto result = state(s[idx - 1] - '0', idx + 1, 0);
		cnt += result.first;
		return state(k, result.second, cnt);
	}
	else if (s[idx] == ')') {
		int result = cnt;
		result *= k;
		return { result,idx + 1 };
	}
	else {
		if (idx + 1 < (int)s.length() && s[idx + 1] == '(') {
			return state(k, idx + 1, cnt);
		}
		else {
			return state(k, idx + 1, cnt + 1);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> s;
	//solve
	auto result=state(1, 0, 0);
	//print
	cout << result.first;
}
