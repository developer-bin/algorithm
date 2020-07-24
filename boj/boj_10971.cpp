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
int n;
int w[11][11];
int ans = MAX_VALUE;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> w[i][j];
		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++)v.push_back(i);
	//solve
	do {
		bool check = true;
		int sum = 0;
		for (int i = 0; i < v.size() - 1; i++) {
			if (w[v[i]][v[i + 1]] == 0) {
				check = false; break;
			}
			sum += w[v[i]][v[i + 1]];
		}
		if (w[v.back()][v.front()] == 0)check = false;
		else sum += w[v.back()][v.front()];
		if (check)ans = min(ans, sum);
	} while (next_permutation(v.begin() + 1, v.end()));
	cout << ans;
}