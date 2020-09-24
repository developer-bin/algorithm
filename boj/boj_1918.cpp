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
stack<char> st;
string postfix_s;
void input() {
	cin >> s;
}
int op_priority(char c) {
	if (c == '*' || c == '/')return 2;
	if (c == '+' || c == '-')return 3;
	if (c == '(')return 4;
	if (c == ')')return 5;
}
void st_process(char now) {
	if (st.empty()) {
		st.push(now);
		return;
	}
	if (now == '(') {
		st.push(now);
		return;
	}
	int top_priority = op_priority(st.top());
	int now_priority = op_priority(now);
	if (now == ')') {
		while (!st.empty()) {
			char top_c = st.top();
			st.pop();
			if (top_c == '(')break;
			postfix_s += top_c;
		}
		return;
	}
	if (top_priority > now_priority) {
		st.push(now);
	}
	else {
		while (!st.empty()) {
			top_priority = op_priority(st.top());
			if (top_priority > now_priority) {
				break;
			}
			postfix_s += st.top();
			st.pop();
		}
		st.push(now);
	}
	return;
}
void st_end_process() {
	while (!st.empty()) {
		postfix_s += st.top();
		st.pop();
	}
}
void solve() {
	for (int i = 0; i < (int)s.length(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			postfix_s += s[i];
		}
		else {
			st_process(s[i]);
		}
	}
	st_end_process();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	input();
	//solve
	solve();
	//print
	cout << postfix_s;
}