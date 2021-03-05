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
int a[6];
int sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 5; i++) {
		cin >> a[i];
		sum += a[i];
	}
	//solve
	sort(a + 1, a + 6);
	//print
	cout << sum / 5 << '\n' << a[3];
	return 0;
}