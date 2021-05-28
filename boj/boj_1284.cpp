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
int sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	while (true) {
		sum = 0;
		cin >> n;
		if (n == 0)break;
		string s = to_string(n);
		for (int i = 0; i < (int)s.length(); i++) {
			if (s[i] == '1')sum += 3;
			else if (s[i] == '0')sum += 5;
			else sum += 4;
		}
		sum += 1;
		cout << sum << '\n';
	}
	//solve
	//print
}