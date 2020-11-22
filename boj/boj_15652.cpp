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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int n, m;
bool visit[9];
vector<int> permu_v;
void permu(int idx,int cnt) {
	if (cnt == m) {
		for (int k : permu_v) {
			cout << k << ' ';
		}cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++) {
		permu_v.push_back(i);
		permu(i,cnt + 1);
		permu_v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	//solve
	permu(1,0);
}