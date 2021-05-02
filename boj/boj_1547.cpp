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
int m;
bool cup[4];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	cup[1] = true;
	//input
	cin >> m;
	//solve
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		swap(cup[x], cup[y]);
	}
	//print
	for (int i = 1; i <= 3; i++) {
		if (cup[i] == true)cout << i;
	}
}