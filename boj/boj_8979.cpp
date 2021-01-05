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
struct node {
	int num;
	int gold;
	int silver;
	int bronze;
};
struct cmp {
	bool operator()(node a,node b) {
		if (a.gold < b.gold) {
			return true;
		}
		else if (a.gold == b.gold) {
			if (a.silver < b.silver) {
				return true;
			}
			else if (a.silver == b.silver) {
				if (a.bronze < b.bronze) {
					return true;
				}
			}
		}
		return false;
	}
};
priority_queue<node, vector<node>, cmp>pq;
int n, k;
int num, gold, silver, bronze;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> num >> gold >> silver >> bronze;
		pq.push({ num,gold,silver,bronze });
	}
	//solve
	int rank = 0;
	int mid_rank = 0;
	int last_g = -1, last_s = -1, last_b = -1;
	while (!pq.empty()) {
		int num = pq.top().num;
		int gold = pq.top().gold;
		int silver = pq.top().silver;
		int bronze = pq.top().bronze;
		pq.pop();
		if (last_g == gold && last_s == silver && last_b == bronze) {
			mid_rank += 1;
			if (num == k) {
				cout << rank;
				return 0;
			}
			continue;
		}
		last_g = gold;
		last_s = silver;
		last_b = bronze;
		rank += (mid_rank + 1);
		mid_rank = 0;
		if (num == k) {
			cout << rank;
			return 0;
		}
	}
	return 0;
	//print
}