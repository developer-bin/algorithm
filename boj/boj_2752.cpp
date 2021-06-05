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
int a[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 0; i < 3; i++) {
		cin >> a[i];
	}
	//solve
	sort(a, a + 3);
	//print
	for (int i = 0; i < 3; i++) {
		cout << a[i]<<' ';
	}
}