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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n, k;
int action[10][10];
vector<int> v[4];
bool visit[10];
bool check;
int idx[4];
int win[4];
bool boundary(int turn) {
	if (turn == 1) {
		if (idx[1] == n)return false;
		else return true;
	}
	if (turn == 2 || turn==3) {
		if (idx[turn] == 20)return false;
		else return true;
	}
}
void dfs(int turn1,int turn2) {
	if (win[1] == k) {
		check = true;
		return;
	}
	if (turn1 > turn2)swap(turn1, turn2);
	if (win[2] == k || win[3] == k)return;
	if (boundary(turn1)==false)return;
	int left_hand = v[turn1][idx[turn1]++];
	if (boundary(turn2)==false)return;
	int right_hand = v[turn2][idx[turn2]++];
	int n_turn = 0;
	if ((turn1 == 1 && turn2 == 2) || (turn1 == 2 && turn2 == 1))n_turn = 3;
	if ((turn1 == 1 && turn2 == 3) || (turn1 == 3 && turn2 == 1))n_turn = 2;
	if ((turn1 == 2 && turn2 == 3) || (turn1 == 3 && turn2 == 2))n_turn = 1;
	switch (action[left_hand][right_hand]) {
	case 2:
		win[turn1] += 1;
		dfs(turn1, n_turn);
		break;
	case 1:
	case 0:
		win[turn2] += 1;
		dfs(turn2, n_turn);
		break;
	}
}
bool checking() {
	check = false;
	for (int i = 1; i <= 3; i++) {
		idx[i] = 0;
		win[i] = 0;
	}
	dfs(1,2);
	return check;
}
bool end_check;
void permu(int cnt) {
	if (cnt == n) {
		if (checking())end_check = true;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (visit[i])continue;
		visit[i] = true;
		v[1].push_back(i);
		permu(cnt + 1);
		if (end_check)return;
		v[1].pop_back();
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> action[i][j];
		}
	}
	for (int i = 1; i <= 20; i++) {
		int num;
		cin >> num;
		v[2].push_back(num);
	}
	for (int i = 1; i <= 20; i++) {
		int num;
		cin >> num;
		v[3].push_back(num);
	}
	//solve
	permu(0);
	if (end_check)cout << 1;
	else cout << 0;
	return 0;
}