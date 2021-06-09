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
int m, d;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> m >> d;
	//solve
	if (m == 2) {
		if (d < 18) {
			cout << "Before";
		}
		else if (d == 18) {
			cout << "Special";
		}
		else if (d > 18) {
			cout << "After";
		}
	}
	else if (m <= 1) {
		cout << "Before";
	}
	else if (m >= 3) {
		cout << "After";
	}
	//print
}