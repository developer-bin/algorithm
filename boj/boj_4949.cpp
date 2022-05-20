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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
string s;

bool checking(stack<char> &st, char c) {
	if (st.empty()) {
		return false;
	}
	if (st.top() == c) {
		st.pop();
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	while (true) {
		//input
		getline(cin, s);
		if (s == ".")break;
		//solve
		stack<char> st;
		bool check = true;
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (checking(st, '(') == false) {
					check = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (checking(st, '[') == false) {
					check = false;
					break;
				}
			}
		}
		if (st.empty() == false || check == false) {
			cout << "no\n";
		}
		else if (check) {
			cout << "yes\n";
		}
	}

}