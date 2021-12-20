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
int t;
stack<int> st;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	int mok = t;
	while (true) {
		int na = mok % 9;
		mok = mok / 9;
		st.push(na);
		if (mok == 0) {
			break;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}