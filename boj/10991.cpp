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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			cout << ' ';
		}
		for (int j = 1; j <= i; j++) {
			cout << "* ";
		}

		cout << '\n';
	}
	//print
}
