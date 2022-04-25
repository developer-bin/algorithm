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
int match[10001][7];
int n;
int ans;

void match_create(int floor,int *input) {
	match[floor][input[1]] = input[6];
	match[floor][input[2]] = input[4];
	match[floor][input[3]] = input[5];
	match[floor][input[4]] = input[2];
	match[floor][input[5]] = input[3];
	match[floor][input[6]] = input[1];
}
void state(int floor, int top_num,int sum) {
	int down_num = match[floor][top_num];
	int max_num = MIN_VALUE;
	for (int i = 1; i <= 6; i++) {
		if (top_num == i || down_num == i)continue;
		max_num = max(max_num, i);
	}
	if (floor + 1 <= n) {
		state(floor + 1, match[floor + 1][top_num], sum + max_num);
	}
	else {
		ans = max(ans, sum + max_num);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int input[7] = { 0, };
		for (int j = 1; j <= 6; j++) {
			cin >> input[j];
		}
		match_create(i,input);
	}
	//solve
	for (int i = 1; i <= 6; i++) {
		state(1, i, 0);
	}
	//print
	cout << ans;
}