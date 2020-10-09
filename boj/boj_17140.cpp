#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int r, c, k;
int a[201][201];
int time;
int rr = 3, cc = 3;
void testprint() {
	for (int i = 1; i <= rr; i++) {
		for (int j = 1; j <= cc; j++) {
			cout << a[i][j] << ' ';
		}cout << '\n';
	}
}
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {//숫자 개수
		if (a.second > b.second)return true;
		else if (a.second == b.second) {
			if (a.first > b.first)return true;
		}
		return false;
	}
};
void row_sort() {
	map<int, int> maps;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	int max_cc = cc;
	for (int i = 1; i <= rr; i++) {
		maps.clear();
		for (int j = 1; j <= cc; j++) {
			if (a[i][j] == 0)continue;
			maps[a[i][j]] += 1;
			a[i][j] = 0;
		}
		for (auto it = maps.begin(); it != maps.end(); it++) {
			int num = (*it).first;
			int cnt = (*it).second;
			pq.push({ num,cnt });
		}
		int idx = 1;
		while (!pq.empty()) {
			int num = pq.top().first;
			int cnt = pq.top().second;
			pq.pop();
			a[i][idx++] = num;
			a[i][idx++] = cnt;
		}
		idx -= 1;
		max_cc = max(max_cc, idx);
	}
	cc = max_cc;
}
void col_sort() {
	map<int, int> maps;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	int max_rr = rr;
	for (int j = 1; j <= cc; j++) {
		maps.clear();
		for (int i = 1; i <= rr; i++) {
			if (a[i][j] == 0)continue;
			maps[a[i][j]] += 1;
			a[i][j] = 0;
		}
		for (auto it = maps.begin(); it != maps.end(); it++) {
			int num = (*it).first;
			int cnt = (*it).second;
			pq.push({ num,cnt });
		}
		int idx = 1;
		while (!pq.empty()) {
			int num = pq.top().first;
			int cnt = pq.top().second;
			pq.pop();
			a[idx++][j] = num;
			a[idx++][j] = cnt;
		}
		idx -= 1;
		max_rr = max(max_rr, idx);
	}
	rr = max_rr;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	//solve
	while (true) {
		if (a[r][c] == k)break;
		if (time == 100) {
			time = -1;
			break;
		}
		if (rr >= cc) {
			row_sort();
		}
		else if (rr < cc) {
			col_sort();
		}
		time += 1;
	}
	cout << time;
}