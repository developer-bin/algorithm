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
string n;
string f;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> f;
	//solve
	for (int i = 0; i <= 9; i++) {
		string tmp_n = n;
		tmp_n[(int)n.length() - 2] = '0';
		tmp_n[(int)n.length() - 1] = ('0' + i);
		if (stoi(tmp_n) % stoi(f) == 0) {
			cout << '0' << i;
			return 0;
		}
	}
	for (int i = 10; i <= 99; i++) {
		string tmp_n = n;
		string s_i = to_string(i);
		tmp_n[(int)n.length() - 2] = s_i[0];
		tmp_n[(int)n.length() - 1] = s_i[1];
		if (stoi(tmp_n) % stoi(f) == 0) {
			cout << s_i;
			return 0;
		}
	}
	//print
	return 0;
}