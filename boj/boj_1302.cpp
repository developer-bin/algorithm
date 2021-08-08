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

struct cmp {
	bool operator()(pair<string, int> a, pair<string, int> b) {
		if(a.second < b.second) {
			return true;
		}
		else if (a.second == b.second) {
			if (a.first > b.first)return true;
		}
		return false;
	}
};

int n;
map<string, int> maps;
priority_queue<pair<string, int>, vector<pair<string, int>>, cmp>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		maps[s] += 1;
	}

	for (auto k : maps) {
		pq.push({ k.first,k.second });
	}

	cout << pq.top().first;
}