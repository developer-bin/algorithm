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
int n;
int money[6] = { 500,100,50,10,5,1 };
int ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	//solve
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		int mok = n / money[i];
		int na = n % money[i];
		n = na;
		ans += mok;
		if (na == 0) {
			break;
		}
	}
	//print
	cout << ans;
	return 0;
}