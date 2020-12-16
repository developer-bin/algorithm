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
vector<pair<int, int>> v;
int grade[51];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		grade[i] = 1;
	}
	//solve
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i == j)continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second) {
				grade[i] += 1;
			}
		}
	}
	//print
	for (int i = 0; i < v.size(); i++) {
		cout << grade[i] << ' ';
	}
}