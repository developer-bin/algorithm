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

int l, a, b, c, d;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> l >> a >> b >> c >> d;


	int math = 0;
	if (b % d >= 1)math += 1;
	math += (b / d);

	int kor = 0;
	if (a % c >= 1)kor += 1;
	kor += (a / c);

	cout << l - max(math, kor);
	
}