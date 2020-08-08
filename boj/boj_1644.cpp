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
int n;
bool era[4000001];
vector<int> eratos;
int ans;
bool dfs(int num, int idx) {
	if (num == n)return true;
	if (num > n)return false;
	if (idx + 1 < eratos.size()) {
		return dfs(num + eratos[idx + 1], idx + 1);
	}
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	for (int i = 2; i <= 4000000; i++) {
		if (era[i] == false) {
			eratos.push_back(i);
			for (int j = i + i; j <= 4000000; j += i) {
				era[j] = true;
			}
		}
	}
	//input
	cin >> n;
	//solve
	for (int i = 0; i < eratos.size(); i++) {
		int s_num = eratos[i];
		if (s_num > n)break;
		if (dfs(s_num, i))ans += 1;
	}
	cout << ans;
}