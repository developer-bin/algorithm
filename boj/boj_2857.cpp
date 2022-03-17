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
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 5; i++) {
		cin >> s;
		for (int j = 0; j < (int)s.length(); j++) {
			string slice_s=s.substr(j, 3);
			if (slice_s == "FBI") {
				ans.push_back(i);
				break;
			}
		}
	}
	//solve
	if (ans.size() == 0) {
		cout << "HE GOT AWAY!";
	}
	else {
		for (int k : ans) {
			cout << k << ' ';
		}
	}
	//print
}