#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
map<string, bool> ans_visit;

bool checking(string s) {
	char maps[4][4] = { 0, };
	int s_idx = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			maps[i][j] = s[s_idx++];
		}
	}
	//가로
	for (int i = 1; i <= 3; i++) {
		set<char> sets;
		for (int j = 1; j <= 3; j++) {
			if (maps[i][j] == '.') {
				sets.clear();
				break;
			}
			sets.insert(maps[i][j]);
		}
		if (sets.size() == 1)return true;
	}
	//세로
	for (int j = 1; j <= 3; j++) {
		set<char> sets;
		for (int i = 1; i <= 3; i++) {
			if (maps[i][j] == '.') {
				sets.clear();
				break;
			}
			sets.insert(maps[i][j]);
		}
		if (sets.size() == 1)return true;
	}
	//대각
	if (maps[1][1] == maps[2][2] && maps[1][1] == maps[3][3] && (maps[1][1]=='O' || maps[1][1]=='X'))return true;
	if (maps[1][3] == maps[2][2] && maps[1][3] == maps[3][1] && (maps[1][3]=='O' || maps[1][3]=='X'))return true;
	return false;
}
void dfs(string s, int cnt,int check) {
	if (cnt == 9) {
		ans_visit[s] = true;
		return;
	}
	if (checking(s)) {
		ans_visit[s] = true;
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (s[i] == '.') {
			string n_s = s;
			if (check == 0) {
				n_s[i] = 'X';
				dfs(n_s, cnt + 1,1);
			}
			else if (check == 1) {
				n_s[i] = 'O';
				dfs(n_s, cnt + 1,0);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	dfs(".........", 0,0);
	//input
	while (true) {
		string s;
		cin >> s;
		if (s == "end")break;
		if (ans_visit[s]) {
			cout << "valid\n";
		}
		else cout << "invalid\n";
	}
}