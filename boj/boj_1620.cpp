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

int n, m;
map<string, int> maps1;
map<int, string> maps2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		maps1[s] = i;
		maps2[i] = s;
	}

	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		if ('A' <= s.front() && s.front() <= 'Z') {
			cout << maps1[s] << '\n';
		}
		else {
			int num = stoi(s);
			cout << maps2[num]<<'\n';
		}
	}
}