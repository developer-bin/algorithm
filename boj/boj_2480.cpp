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

map<int, int>maps;
int a, b, c;
bool check = true;
int ans;
int max_num=MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;

	maps[a] += 1;
	maps[b] += 1;
	maps[c] += 1;

	for (auto k : maps) {
		if (k.second == 2) {
			check = false;
			ans = 1000 + k.first * 100;
		}
		else if (k.second == 3) {
			check = false;
			ans = 10000 + k.first * 1000;
		}
		max_num = max(max_num, k.first);
	}

	if (check == true) {
		ans = max_num * 100;
	}

	cout << ans;
}