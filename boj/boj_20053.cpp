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
int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		
		int min_num = MAX_VALUE, max_num = MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;

			min_num = min(min_num, num);
			max_num = max(max_num, num);
		}

		cout << min_num << ' ' << max_num << '\n';
	}
}