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
int t;
vector<pair<string, int>> v;

bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second > b.second)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> t;
	while (t--) {
		v.clear();
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string s;
			int num;
			cin >> s >> num;
			v.push_back({ s,num });
		}
		sort(v.begin(), v.end(), cmp);
		cout << v.front().first<<'\n';
	}
	//solve
	//print
}
