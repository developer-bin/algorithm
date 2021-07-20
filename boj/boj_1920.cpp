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
unordered_set<int> sets;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sets.insert(num);
	}
	
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		if (sets.find(num) != sets.end()) {
			cout << "1\n";
		}
		else cout << "0\n";
	}
}