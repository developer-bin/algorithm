#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int a[5];

void print() {
	for (int i = 0; i < 5; i++) {
		cout << a[i] << ' ';
	}cout << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	//solve
	while (true) {
		for (int i = 0; i <= 3; i++) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				print();
			}
		}
		bool check = true;
		for (int i = 0; i <= 3; i++) {
			if (a[i] > a[i + 1]) {
				check = false;
				break;
			}
		}
		if (check)break;
	}
	//print
	return 0;
}