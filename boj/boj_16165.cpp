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
map<string, vector<string>> team_name;
map<string, string>member_name;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		
		int tmp;
		cin >> tmp;

		vector<string> v;
		for (int j = 1; j <= tmp; j++) {
			string ss;
			cin >> ss;
			
			v.push_back(ss);
			member_name[ss] = s;
		}

		sort(v.begin(), v.end());

		team_name[s] = v;
	}

	for (int i = 1; i <= m; i++) {
		string s;
		int n;

		cin >> s >> n;

		if (n == 0) {
			for (int j = 0; j < team_name[s].size(); j++) {
				cout << team_name[s][j] << '\n';
			}
		}
		else if (n == 1) {
			cout << member_name[s] << '\n';
		}
	}
}