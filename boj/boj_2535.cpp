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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
struct node {
	int country;
	int stud_num;
	int grade;
};
int cnt[1000001];
int n;
int loop_cnt;
struct cmp {
	bool operator()(node a, node b) {
		if (a.grade < b.grade)return true;
		return false;
	}
};
priority_queue<node, vector<node>, cmp>pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int country, stud_num, grade;
		cin >> country >> stud_num >> grade;
		pq.push({ country,stud_num,grade });
	}
	//solve
	while (!pq.empty() && loop_cnt<3) {
		int country = pq.top().country;
		int stud_num = pq.top().stud_num;
		pq.pop();
		if (cnt[country] >= 2)continue;
		cnt[country] += 1;
		cout << country << ' ' << stud_num << '\n';
		loop_cnt += 1;
	}
	//print
}