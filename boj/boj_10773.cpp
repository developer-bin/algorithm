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
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
stack<int> st;
int n;
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num == 0)st.pop();
		else st.push(num);
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans;
}