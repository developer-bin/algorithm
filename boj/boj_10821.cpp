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
string s;
stringstream ss;
string tmp_s;
int cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	//solve
	ss.str(s);
	while (getline(ss, tmp_s, ',')) {
		cnt += 1;
	}
	//print
	cout << cnt;
}