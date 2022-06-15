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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n;
vector<string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int j = 0; j < (int)v[0].length(); j++) {
		char c = v[0][j];
		bool check = true;
		for (int i = 0; i < v.size(); i++) {
			if (c != v[i][j]) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << c;
		}
		else {
			cout << "?";
		}
	}
}
