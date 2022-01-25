#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int ans;
int stick = 64;
int x;
int cnt = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> x;
	//solve
	while (true) {
		if (ans + stick > x) {
			stick /= 2;
			if (ans + stick < x) {
				ans += stick;
				cnt += 1;
			}
		}
		else break;
	}
	//print
	cout << cnt;
}