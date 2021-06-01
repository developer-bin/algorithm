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
int x, y;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> x >> y;
	//solve
	if (x > 0 && y > 0)cout << 1;
	else if (x < 0 && y>0)cout << 2;
	else if (x < 0 && y < 0)cout << 3;
	else if (x > 0 && y < 0)cout << 4;
	//print
}