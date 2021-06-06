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
unordered_map<int, int> maps;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	int a, b, c;
	cin >> a >> b >> c;
	//solve
	maps[a] += 1;
	maps[b] += 1;
	maps[c] += 1;
	//print
	if (maps.size() == 1 && maps.count(60))cout << "Equilateral";
	else if ((a + b + c) == 180 && maps.size() == 2)cout << "Isosceles";
	else if ((a + b + c) == 180 && maps.size() == 3)cout << "Scalene";
	else if ((a + b + c) != 180)cout << "Error";
}