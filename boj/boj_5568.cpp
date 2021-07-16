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
#include <stack>
#include <list>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, k;
int card[11];
bool visit[11];
unordered_set<string> sets;
vector<int> permu_v;
void state(int cnt) {
	if (cnt == k) {
		string s;
		for (int i = 0; i < permu_v.size(); i++) {
			s+=to_string(permu_v[i]);
		}
		sets.insert(s);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			permu_v.push_back(card[i]);
			state(cnt + 1);
			permu_v.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> k;
	//solve
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	state(0);
	cout << sets.size();
}