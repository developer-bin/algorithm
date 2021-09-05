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

	cin >> t;
	for (int i = 1; i <= t; i++) {
		int num;
		cin >> num;

		int sum = 0;
		for (int j = 1; j < num; j++) {
			if (num % j == 0)sum += j;
		}

		if (sum < num) {
			cout << "Deficient\n";
		}
		else if (sum == num) {
			cout << "Perfect\n";
		}
		else if (sum > num) {
			cout << "Abundant\n";
		}
	}
}