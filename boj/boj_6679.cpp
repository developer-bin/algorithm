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

int convert(int mok, int num) {
	string s;
	int sum = 0;
	while (true) {
		int na = mok % num;
		mok /= num;
		s += (na + '0');
		if (mok < num) {
			s += (mok + '0');
			break;
		}
	}
	for (int i = 0; i < (int)s.length(); i++) {
		sum += (s[i] - '0');
	}
	return sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	//solve
	for (int i = 1000; i <= 9999; i++) {
		int a = convert(i, 10);
		int b = convert(i, 12);
		int c = convert(i, 16);
		if (a == b && a == c && b == c) {
			cout << i << '\n';
		}
	}
	//print
}