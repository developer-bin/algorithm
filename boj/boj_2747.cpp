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
int d[46];
int f(int n) {
	if (n == 0) {
		return d[n] = 0;
	}
	else if (n == 1) {
		return d[n] = 1;
	}
	else { 
		if (d[n] != -1)return d[n];
		return d[n] = f(n - 1) + f(n - 2); 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	//solve
	//print
	cout << f(n);
}