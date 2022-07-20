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
set<string> visit_sets;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool boundary(int x, int y) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
vector<vector<char>> string_to_maps(string s) {
	vector<vector<char>> maps(3,vector<char>(3));
	for (int i = 0; i < (int)s.length(); i++) {
		maps[i / 3][i % 3] = s[i];
	}
	return maps;
}
string maps_to_string(vector<vector<char>> maps) {
	string s;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].size(); j++) {
			s += maps[i][j];
		}
	}
	return s;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	string s;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			string tmp_s;
			cin >> tmp_s;
			s += tmp_s;
		}
	}
	//solve
	queue<pair<string, int>> q;
	visit_sets.insert(s);
	q.push({ s,0 });
	while (!q.empty()) {
		string s = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (s == "123456780") {
			cout << cnt;
			return 0;
		}
		vector<vector<char>> maps = string_to_maps(s);
		int c_x = 0;
		int c_y = 0;
		for (int i = 0; i < maps.size(); i++) {
			for (int j = 0; j < maps[i].size(); j++) {
				if (maps[i][j] == '0') {
					c_x = i;
					c_y = j;
					break;
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int c_x2 = c_x + dx[i];
			int c_y2 = c_y + dy[i];
			if (boundary(c_x2, c_y2)) {
				swap(maps[c_x][c_y], maps[c_x2][c_y2]);
				string n_s = maps_to_string(maps);
				if (visit_sets.find(n_s) == visit_sets.end()) {
					visit_sets.insert(n_s);
					q.push({ n_s,cnt + 1 });
				}
				swap(maps[c_x][c_y], maps[c_x2][c_y2]);
			}
		}
	}
	//print
	cout << -1;
	return 0;
}
