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
int n, m, J;
int a[21];
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m >> J;
	int left = 1;
	int right = m;
	for (int i = 1; i <= J; i++) {
		int col;
		cin >> col;
		if (col < left) {
			int diff = left - col;
			ans += diff;
			left -= diff;
			right -= diff;
		}
		else if (right < col) {
			int diff = col - right;
			ans += diff;
			left += diff;
			right += diff;
		}
	}
	//solve
	cout << ans;
}