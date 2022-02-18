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
int b[11];
int a_cnt;
int b_cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= 10; i++) {
		cin >> b[i];
	}
	//solve
	for (int i = 1; i <= 10; i++) {
		if (a[i] > b[i]) {
			a_cnt += 1;
		}
		else if (a[i] < b[i]) {
			b_cnt += 1;
		}
	}
	//print
	if (a_cnt > b_cnt) {
		cout << 'A';
	}
	else if (a_cnt < b_cnt) {
		cout << 'B';
	}
	else {
		cout << 'D';
	}
}