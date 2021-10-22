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

string s;
bool check = false;

void state(int s_idx, int e_idx) {

	if (s_idx == e_idx) {
		check = true;
		return;
	}

	if (s_idx + 1 == e_idx && s[s_idx] == s[e_idx]) {
		check = true;
		return;
	}

	if (s[s_idx] == s[e_idx]) {
		state(s_idx + 1, e_idx - 1);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	state(0, (int)s.length() - 1);

	if (check == true) {
		cout << "true";
	}
	else cout << "false";
}