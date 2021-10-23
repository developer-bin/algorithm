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
int a[6] = { 1,2,3,3,4,10 };
int b[7] = { 1,2,2,2,3,5,10 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	for (int battle = 1; battle <= t; battle++) {
		cout << "Battle " << battle << ": ";

		int sum_a = 0, sum_b = 0;

		for (int i = 0; i < 6; i++) {
			int num;
			cin >> num;
			sum_a += (a[i] * num);
		}

		for (int i = 0; i < 7; i++) {
			int num;
			cin >> num;
			sum_b += (b[i] * num);
		}

		if (sum_a > sum_b) {
			cout << "Good triumphs over Evil\n";
		}
		else if (sum_a < sum_b) {
			cout << "Evil eradicates all trace of Good\n";
		}
		else {
			cout << "No victor on this battle field\n";
		}
	}
}