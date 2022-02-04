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
#define MOD 1000000009
#define ll long long
using namespace std;
int n;
int weight[21][21];
bool check[21];
int ans = MAX_VALUE;

void go() {
	vector<int> left, right;
	for (int i = 1; i <= n; i++) {
		if (check[i]) {
			left.push_back(i);
		}
		else {
			right.push_back(i);
		}
	}
	int left_sum = 0, right_sum = 0;
	for (int i = 0; i < left.size() - 1; i++) {
		for (int j = i + 1; j < left.size(); j++) {
			left_sum += weight[left[i]][left[j]] + weight[left[j]][left[i]];
		}
	}
	for (int i = 0; i < right.size() - 1; i++) {
		for (int j = i + 1; j < right.size(); j++) {
			right_sum += weight[right[i]][right[j]] + weight[right[j]][right[i]];
		}
	}
	ans = min(ans, abs(left_sum - right_sum));
}
void combi(int idx, int cnt) {
	if (n / 2 == cnt) {
		go();
		return;
	}
	for (int i = idx; i <= n; i++) {
		check[i] = true;
		combi(i + 1, cnt + 1);
		check[i] = false;
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
		for (int j = 1; j <= n; j++) {
			cin >> weight[i][j];
		}
	}
	//solve
	combi(1, 0);
	cout << ans;
}