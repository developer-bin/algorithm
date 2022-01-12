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
int n, k, l;
int head_x = 1, head_y = 1;
int tail_x = 1, tail_y = 1;
int time, head_dist = 1;
bool apple[101][101];
queue<pair<int, char>> dist_q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
bool snake[101][101];
int dist[101][101];

bool boundary(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= n;
}
int move() {
	int hnx = head_x + dx[head_dist];
	int hny = head_y + dy[head_dist];
	if (boundary(hnx, hny) == false)return 1;
	if (snake[hnx][hny])return 1;
	if (apple[hnx][hny]) {
		apple[hnx][hny] = false;
	}else {
		snake[tail_x][tail_y] = false;
		int ntx = tail_x + dx[dist[tail_x][tail_y]];
		int nty = tail_y + dy[dist[tail_x][tail_y]];
		tail_x = ntx;
		tail_y = nty;
	}
	snake[hnx][hny] = true;
	dist[hnx][hny] = head_dist;
	head_x = hnx;
	head_y = hny;
	return 0;
}
int convert_left_dist(int dist) {
	int n_dist = dist - 1;
	if (n_dist == -1)n_dist = 3;
	return n_dist;
}
int convert_right_dist(int dist) {
	return (dist + 1) % 4;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		apple[x][y] = true;
	}
	cin >> l;
	for (int i = 1; i <= l; i++) {
		int time;
		char dist;
		cin >> time >> dist;
		dist_q.push({ time,dist });
	}
	//solve
	snake[1][1] = true;
	dist[1][1] = 1;
	while (true) {
		if(move())break;
		time += 1;
		if (dist_q.empty()==false && dist_q.front().first == time) {
			if (dist_q.front().second == 'L') {
				head_dist = convert_left_dist(head_dist);
			}
			else {
				head_dist = convert_right_dist(head_dist);
			}
			dist[head_x][head_y] = head_dist;
			dist_q.pop();
		}
	}
	cout << time + 1;
}