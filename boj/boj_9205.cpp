#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int t, n;
map<pair<int, int>, bool>visit;
vector<pair< int, int>> v;
int sx, sy, ex, ey;
bool ans;
void dfs(int x, int y) {
	for (int i = 0; i < v.size(); i++) {
		if (ans)return;
		int nx = v[i].first;
		int ny = v[i].second;
		if (visit[{nx, ny}] == false) {
			int dist = abs(x - nx) + abs(y - ny);
			if (dist <= 20*50) {
				visit[{nx, ny}] = true;
				dfs(nx, ny);
				//visit[{nx, ny}] = false;
			}
		}
	}
	if ((abs(x - ex) + abs(y - ey)) <= 20*50) {
		ans = true;
		return;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) {
		//init
		visit.clear();
		v.clear();
		ans = false;
		//input
		cin >> n;
		cin >> sx >> sy;
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		cin >> ex >> ey;
		//solve
		visit[{sx, sy}] = true;
		dfs(sx, sy);
		//print
		if (ans)cout << "happy\n";
		else cout << "sad\n";
	}
}