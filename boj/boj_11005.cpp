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
int n;
int b;
stack<int> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> b;
	//solve
	int na;
	if (n < b) {
		st.push(n);
	}
	else {
		while (true) {
			na = n % b;
			n /= b;
			if (n < b) {
				st.push(na);
				st.push(n);
				break;
			}
			st.push(na);
		}
	}
	//print
	while (!st.empty()) {
		int num = st.top();
		st.pop();
		if (num >= 10) {
			cout << (char)('A'+num-10);
		}
		else {
			cout << num;
		}
	}
}
