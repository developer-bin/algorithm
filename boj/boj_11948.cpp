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
int a, b, c, d, e, f;
int sum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> a >> b >> c >> d >> e >> f;
	//solve
	sum = a + b + c + d;
	sum -= min({ a,b,c,d });
	sum += max({ e,f });
	//print
	cout << sum;
}