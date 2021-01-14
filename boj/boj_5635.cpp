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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
struct node {
	string name;
	int d;
	int m;
	int y;
};
bool cmp(node a, node b) {
	if (a.y < b.y) {
		return true;
	}
	else if (a.y == b.y) {
		if (a.m < b.m) {
			return true;
		}
		else if (a.m == b.m) {
			if (a.d < b.d) {
				return true;
			}
		}
	}
	return false;
}
int n;
vector<node> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		int d, m, y;
		cin >> s >> d >> m >> y;
		v.push_back({ s,d,m,y });
	}
	//solve
	sort(v.begin(), v.end(), cmp);
	//print
	cout << v.back().name << '\n' << v.front().name;
}