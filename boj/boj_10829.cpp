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
ll n;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	ll mok=n;
	ll na;
	while (true) {
		na = mok % 2;
		mok /= 2;
		st.push(na);
		if (mok < 2) {
			st.push(mok);
			break;
		}
	}
	//print
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}