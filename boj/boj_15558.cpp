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
#define MOD 1000000009
#define ll long long
using namespace std;
int maps[2][100001];
int n, k;
bool visit[2][100001];
struct vertex {
	int lr; int num; int time;
	//0Àº left, 1Àº right
};
queue<vertex> q;
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &maps[0][i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%1d", &maps[1][i]);
	}
	//solve
	bool check = false;
	q.push({ 0,1,0 });
	while (!q.empty()) {
		int lr = q.front().lr;
		int num = q.front().num;
		int time = q.front().time;
		q.pop();
		int n_time = time + 1;
		int n_num = num + 1;
		if (n_num >= n+1) {
			check = true;
			break;
		}
		if (n_num > n_time && maps[lr][n_num] == 1 && visit[lr][n_num] == false) {
			visit[lr][n_num] = true;
			q.push({ lr,n_num,n_time });
		}
		n_num = num - 1;
		if (n_num >= n + 1) {
			check = true;
			break;
		}
		if (n_num > n_time && maps[lr][n_num] == 1 && visit[lr][n_num]==false) {
			visit[lr][n_num] = true;
			q.push({ lr,n_num,n_time });
		}
		int n_lr = (lr + 1) % 2;
		n_num = num + k;
		if (n_num >= n + 1) {
			check = true;
			break;
		}
		if (n_num > n_time && maps[n_lr][n_num] == 1 && visit[n_lr][n_num] == false) {
			visit[n_lr][n_num] = true;
			q.push({ n_lr,n_num,n_time });
		}
	}
	if (check)cout << 1;
	else cout << 0;
}