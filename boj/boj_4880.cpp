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

int a, b, c;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)break;

		if (c - b == b - a) {
			cout << "AP " << c + (c - b) << '\n';
		}
		else {
			cout << "GP " << c * (c / b) << '\n';
		}
	}
}