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

string s1, s2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s1 >> s2;

	bool check = false;

	for (int i = 0; i < (int)s1.length(); i++) {
		string tmp_s = s1.substr(i, (int)s2.length());
		if (s2 == tmp_s)check = true;
	}

	if (check == true)cout << "go";
	else cout << "no";
}