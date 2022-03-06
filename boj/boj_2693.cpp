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
int n;
int a[1000001];
int tmp_a[1000001];
int t;

void merge(int left_l, int left_r, int right_l, int right_r) {
	int idx = 0;
	int s_idx = left_l;
	while (left_l <= left_r && right_l <= right_r) {
		if (a[left_l] >= a[right_l]) {
			tmp_a[idx++] = a[left_l];
			left_l += 1;
		}
		else if (a[left_l] < a[right_l]) {
			tmp_a[idx++] = a[right_l];
			right_l += 1;
		}
	}
	while (left_l <= left_r)tmp_a[idx++] = a[left_l++];
	while (right_l <= right_r)tmp_a[idx++] = a[right_l++];
	for (int i = 0; i < idx; i++) {
		a[s_idx++] = tmp_a[i];
	}
}
void slice(int l, int r) {
	if (l >= r)return;
	int m = (l + r) / 2;
	slice(l, m);
	slice(m + 1, r);
	merge(l,m,m+1,r);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		for (int i = 0; i < 10; i++) {
			cin >> a[i];
		}
		slice(0, 9);
		cout << a[2]<<'\n';
	}
	//print

	return 0;
}