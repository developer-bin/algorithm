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
ll a, b, c;
string op1, op2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> a >> op1 >> b >> op2 >> c;
		
		bool check = true;

		if (op1 == "*") {
			if (a * b != c)check = false;
		}
		else if (op1 == "-") {
			if (a - b != c)check = false;
		}
		else if (op1 == "+") {
			if (a + b != c)check = false;
		}
		else if (op1 == "/") {
			if (a / b != c)check = false;
		}

		if (check)cout << "correct\n";
		else cout << "wrong answer\n";
	}
}