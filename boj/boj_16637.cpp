#include <iostream>
#include <algorithm>
#include <string>
#define MIN_VALUE -200000000
using namespace std;
int n;
string s;
int ans = MIN_VALUE;
int calculate(int a, int b, char c) {
	if (c == '+') {
		return a + b;
	}
	if (c == '-') {
		return a - b;
	}
	if (c == '*') {
		return a * b;
	}
}
void state(int idx, int sum) {
	if (idx == n + 2) {
		//end
		ans = max(ans, sum);
		return;
	}
	
	if (idx + 2 <= n) {
		//°ýÈ£ o
		string tmp_s = s.substr(idx, 3);
		int num = calculate(tmp_s[0] - '0', tmp_s[2] - '0', tmp_s[1]);
		state(idx + 4, calculate(sum, num, s[idx - 1]));
	}
	state(idx + 2, calculate(sum, s[idx] - '0', s[idx - 1]));
}
int main() {
	//init
	//input
	cin >> n;
	cin >> s;
	s.insert(s.begin(), '+');
	//solve
	state(1, 0);
	//print
	cout << ans;
	return 0;
}