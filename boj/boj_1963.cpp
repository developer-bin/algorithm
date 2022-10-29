#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
string a, b;
int t;
bool visit[10000];
bool eratos[10000];

bool checking(string s) {
	int check = false;
	for (int i = 0; i < 4; i++) {
		if (s[i] != '0') {
			check = true;
			continue;
		}
		if (s[i] == '0' && check == false) {
			return false;
		}
	}
	if (eratos[stoi(s)] == false) {
		return true;
	}
	else return false;
}
int bfs() {
	memset(visit, false, sizeof(visit));
	queue<pair<string, int>> q;
	q.push({ a,0 });
	visit[stoi(a)] = true;
	while (!q.empty()) {
		string num_s = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if(checking(num_s)==false)continue;
		if (num_s == b) {
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			for (char c = '0'; c <= '9'; c++) {
				if (num_s[i] == c)continue;
				string n_num_s = num_s;
				n_num_s[i] = c;
				if (visit[stoi(n_num_s)] == false) {
					visit[stoi(n_num_s)] = true;
					q.push({ n_num_s,cnt + 1 });
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	eratos[0] = eratos[1] = true;
	for (int i = 2; i < 10000; i++) {
		if (eratos[i] == false) {
			for (int j = i + i; j < 10000; j += i) {
				eratos[j] = true;
			}
		}
	}
	cin >> t;
	while (t--) {
		//input
		cin >> a >> b;
		//solve
		cout<<bfs()<<'\n';
	}
}
