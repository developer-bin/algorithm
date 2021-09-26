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

int a, b, c;
int d;
int times;
int h, m, s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c >> d;

	times = (a * 3600) + (b * 60) + c + d;

	h = (times / 3600) % 24;
	m = (times % 3600) / 60;
	s = (times % 3600) % 60;

	cout << h << ' ' << m << ' ' << s;
}