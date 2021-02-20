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
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 8; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//solve
	bool check = true;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != i + 1) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << "ascending";
		return 0;
	}
	check = true;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] != 8-i) {
			check = false;
			break;
		}
	}
	if (check) {
		cout << "descending";
		return 0;
	}
	cout << "mixed";
	return 0;
}