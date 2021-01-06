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
map<string, bool> maps;
stack<string> st;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string name, in_out;
		cin >> name >> in_out;
		if (in_out == "enter") {
			maps[name] = true;
		}
		else if (in_out == "leave") {
			maps[name] = false;
		}
	}
	//solve
	for (map<string, bool>::iterator it = maps.begin(); it != maps.end(); it++) {
		if ((*it).second == true) {
			st.push((*it).first);
		}
	}
	//print
	while (!st.empty()) {
		cout << st.top() << '\n';
		st.pop();
	}
}