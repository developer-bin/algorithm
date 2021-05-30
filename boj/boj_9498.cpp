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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	if (n >= 90) {
		cout << "A";
	}
	else if (n >= 80) {
		cout << "B";
	}
	else if (n >= 70) {
		cout << "C";
	}
	else if (n >= 60) {
		cout << "D";
	}
	else cout << "F";
	//print
}