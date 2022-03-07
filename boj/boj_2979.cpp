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
int car[101];
int money[4];
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	for (int i = 1; i <= 3; i++) {
		cin >> money[i];
	}
	for (int i = 1; i <= 3; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j < e; j++) {
			car[j] += 1;
		}
	}
	//solve
	for (int i = 0; i <= 100; i++) {
		ans += (money[car[i]] * car[i]);
	}
	//print
	cout << ans;
}