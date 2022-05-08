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
int joi_cnt;
int ioi_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (i + 2 >= (int)s.length())break;
		string sub_s = s.substr(i, 3);
		if (sub_s == "JOI")joi_cnt += 1;
		else if (sub_s == "IOI")ioi_cnt += 1;
	}
	//print
	cout << joi_cnt << '\n' << ioi_cnt;
}