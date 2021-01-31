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
int a[11];
int sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= 10; i++) {
		sum += a[i];
		if (sum == 100) {
			break;
		}
		else if (sum > 100) {
			if (abs(sum - 100) > abs((sum - a[i]) - 100)) {
				sum = sum - a[i];
			}
			break;
		}
	}
	//print
	cout << sum;
}
