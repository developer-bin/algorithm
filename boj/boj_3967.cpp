#include <iostream>
#include <unordered_set>
using namespace std;
char maps[5][9];
bool alpa_visit[26];
unordered_set<int> sets;
int s1, s2, s3, s4, s5, s6;
int c_s1, c_s2, c_s3, c_s4, c_s5, c_s6;
bool go_add() {
	int s1 = maps[0][4] + maps[1][3] + maps[2][2] + maps[3][1] - (4 * 'A');
	int s2 = maps[0][4] + maps[1][5] + maps[2][6] + maps[3][7] - (4 * 'A');
	int s3 = maps[1][1] + maps[1][3] + maps[1][5] + maps[1][7] - (4 * 'A');
	int s4 = maps[3][1] + maps[3][3] + maps[3][5] + maps[3][7] - (4 * 'A');
	int s5 = maps[1][1] + maps[2][2] + maps[3][3] + maps[4][4] - (4 * 'A');
	int s6 = maps[1][7] + maps[2][6] + maps[3][5] + maps[4][4] - (4 * 'A');
	sets.clear();
	sets.insert(s1); sets.insert(s2); sets.insert(s3);
	sets.insert(s4); sets.insert(s5); sets.insert(s6);
	if (sets.size() == 1)return true;
	else return false;
}
void sum_checking(int x, int y) {
	if (x == 0 && y == 4 || x == 1 && y == 3 || x == 2 && y == 2 || x == 3 && y == 1) {
		s1 += maps[x][y]-'A'; c_s1 += 1;
	}
	else if (x == 0 && y == 4 || x == 1 && y == 5 || x == 2 && y == 6 || x == 3 && y == 7) {
		s2 += maps[x][y] - 'A'; c_s2 += 1;
	}
	else if (x == 1 && y == 1 || x == 1 && y == 3 || x == 1 && y == 5 || x == 1 && y == 7) {
		s3 += maps[x][y] - 'A'; c_s3 += 1;
	}
	else if (x == 3 && y == 1 || x == 3 && y == 3 || x == 3 && y == 5 || x == 3 && y == 7) {
		s4 += maps[x][y] - 'A'; c_s4 += 1;
	}
	else if (x == 1 && y == 1 || x == 2 && y == 2 || x == 3 && y == 3 || x == 4 && y == 4) {
		s5 += maps[x][y] - 'A'; c_s5 += 1;
	}
	else if (x == 1 && y == 7 || x == 2 && y == 6 || x == 3 && y == 5 || x == 4 && y == 4) {
		s6 += maps[x][y] - 'A'; c_s6 += 1;
	}
}
void reverse_sum_checking(int x, int y) {
	if (x == 0 && y == 4 || x == 1 && y == 3 || x == 2 && y == 2 || x == 3 && y == 1) {
		s1 -= maps[x][y] - 'A'; c_s1 -= 1;
	}
	else if (x == 0 && y == 4 || x == 1 && y == 5 || x == 2 && y == 6 || x == 3 && y == 7) {
		s2 -= maps[x][y] - 'A'; c_s2 -= 1;
	}
	else if (x == 1 && y == 1 || x == 1 && y == 3 || x == 1 && y == 5 || x == 1 && y == 7) {
		s3 -= maps[x][y] - 'A'; c_s3 -= 1;
	}
	else if (x == 3 && y == 1 || x == 3 && y == 3 || x == 3 && y == 5 || x == 3 && y == 7) {
		s4 -= maps[x][y] - 'A'; c_s4 -= 1;
	}
	else if (x == 1 && y == 1 || x == 2 && y == 2 || x == 3 && y == 3 || x == 4 && y == 4) {
		s5 -= maps[x][y] - 'A'; c_s5 -= 1;
	}
	else if (x == 1 && y == 7 || x == 2 && y == 6 || x == 3 && y == 5 || x == 4 && y == 4) {
		s6 -= maps[x][y] - 'A'; c_s6 -= 1;
	}
}
bool sum_count_checking() {
	if (c_s1 == 4) { if (s1 != 22)return false; }
	if (c_s2 == 4) { if (s2 != 22)return false; }
	if (c_s3 == 4) { if (s3 != 22)return false; }
	if (c_s4 == 4) { if (s4 != 22)return false; }
	if (c_s5 == 4) { if (s5 != 22)return false; }
	if (c_s6 == 4) { if (s6 != 22)return false; }
	return true;
}
bool check = false;
void dfs(int num) {
	int x = num / 9;
	int y = num % 9;
	if (x == 4 && y == 5) {
		if (go_add()) { check = true; }
		return;
	}
	if (maps[x][y] == 'x') {
		for (char c = 'A'; c <= 'L'; c++) {
			if (alpa_visit[c - 'A'] == false) {
				alpa_visit[c - 'A'] = true;
				maps[x][y] = c;
				sum_checking(x, y);
				if (sum_count_checking() == false) {
					reverse_sum_checking(x, y);
					maps[x][y] = 'x';
					alpa_visit[c - 'A'] = false;
					continue;
				}
				dfs(num + 1);
				if (check)return;
				reverse_sum_checking(x, y);
				maps[x][y] = 'x';
				alpa_visit[c - 'A'] = false;
			}
		}
	}
	else {
		dfs(num + 1);
		if (check)return;
	}
}
int main() {
	//init
	//input
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &maps[i][j]);
			if (maps[i][j] != 'x' && maps[i][j] != '.') {
				alpa_visit[maps[i][j] - 'A'] = true;
			}
		}
	}
	//solve
	dfs(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%c", maps[i][j]);
		}printf("\n");
	}
}