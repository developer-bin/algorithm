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
string a, op, b;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> a >> op >> b;
	//solve
	//print
	if (op == "*") {
		cout << '1';
		for (int i = 1; i <= (int)a.length() - 1 + (int)b.length() - 1; i++) {
			cout << '0';
		}
	}
	else {
		if((int)a.length()<(int)b.length()){
			b[(int)b.length() - (int)a.length()] = '1';
			cout << b;
		}
		else if ((int)a.length() == (int)b.length()) {
			a[0] = '2';
			cout << a;
		}
		else {
			a[(int)a.length() - (int)b.length()] = '1';
			cout << a;
		}
	}
}