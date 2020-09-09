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
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int t, f;
unordered_map<string, pair<string, int>> p;
pair<string, int> Find(string v) {
	if ("" == p[v].first) {
		p[v].first = v;
		p[v].second = 1;
		return { v,1 };
	}
	else if (p[v].first == v) {
		return { v,p[v].second };
	}else {
		pair<string, int> result = Find(p[v].first);
		p[v].first = result.first;
		p[v].second = result.second;
		return result;
	}
}
int Union(string a, string b) {
	pair<string,int> p1_and_cnt = Find(a);
	pair<string,int> p2_and_cnt = Find(b);
	if (p[p1_and_cnt.first].first != p[p2_and_cnt.first].first) {
		p[p1_and_cnt.first].first = p[p2_and_cnt.first].first;
		int sum_cnt = p[p1_and_cnt.first].second + p[p2_and_cnt.first].second;
		p[p1_and_cnt.first].second = sum_cnt;
		p[p2_and_cnt.first].second = sum_cnt;
	}
	return p[p1_and_cnt.first].second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		p.clear();
		cin >> f;
		for (int i = 1; i <= f; i++) {
			string from, to;
			cin >> from >> to;
			cout<<Union(from, to)<<'\n';
		}
	}
	//print
	return 0;
}