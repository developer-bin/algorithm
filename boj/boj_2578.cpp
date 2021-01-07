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
int maps[6][6];
bool visit[6][6];
void sketch(int num) {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (maps[i][j] == num)visit[i][j] = true;
		}
	}
}
bool checking() {
	int bingo = 0;
	for (int i = 1; i <= 5; i++) {
		bool check = true;
		for (int j = 1; j <= 5; j++) {
			if (visit[i][j] == false) {
				check = false;
				break;
			}
		}
		if (check)bingo += 1;
	}
	for (int j = 1; j <= 5; j++) {
		bool check = true;
		for (int i = 1; i <= 5; i++) {
			if (visit[i][j] == false) {
				check = false;
				break;
			}
		}
		if (check)bingo += 1;
	}
	bool check = true;
	for (int i = 1; i <= 5; i++) {
		if (visit[i][i] == false) {
			check = false;
			break;
		}
	}
	if (check)bingo += 1;
	check = true;
	for (int i = 1; i <= 5; i++) {
		if (visit[i][6 - i] == false) {
			check = false;
			break;
		}
	}
	if (check)bingo += 1;
	if (bingo >= 3)return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> maps[i][j];
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int num;
			cin >> num;
			sketch(num);
			cnt += 1;
			if (checking()) {
				cout << cnt;
				return 0;
			}
		}
	}
	//solve
	//print
	return 0;
}