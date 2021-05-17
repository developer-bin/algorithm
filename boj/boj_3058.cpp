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
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int min_num = MAX_VALUE;
		int sum = 0;
		for (int i = 1; i <= 7; i++) {
			int num;
			cin >> num;
			if (num % 2 == 0) {
				sum += num;
				if (min_num > num) {
					min_num = num;
				}
			}
		}
		cout << sum << ' ' << min_num << '\n';
	}
	//print
}