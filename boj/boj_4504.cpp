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
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	while (true) {
		int k;
		cin >> k;
		if (k == 0)break;
		if (k % n == 0) {
			cout << k << " is a multiple of " << n << ".\n";
		}
		else {
			cout << k << " is NOT a multiple of " << n << ".\n";
		}
	}
	//print
}