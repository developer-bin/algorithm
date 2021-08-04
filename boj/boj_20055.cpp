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
int a[201];
bool robot[201];
queue<int> robot_order;
int level = 1;

bool robot_exit_checking(bool* robot) {
	if (robot[n - 1] == true) {
		robot[n - 1] = false;
		return true;
	}
	return false;
}

void rotate(int* a, bool* robot) {
	int tmp_a[201];
	for (int i = 0; i < 2 * n - 1; i++) {
		tmp_a[i + 1] = a[i];
	}
	tmp_a[0] = a[2 * n - 1];

	memcpy(a, tmp_a, sizeof(tmp_a));

	bool tmp_robot[201];
	for (int i = 0; i < 2 * n - 1; i++) {
		tmp_robot[i + 1] = robot[i];
	}
	tmp_robot[0] = robot[2 * n - 1];

	memcpy(robot, tmp_robot, sizeof(tmp_robot));

	robot_exit_checking(robot);

	int q_size = robot_order.size();
	while (q_size--) {
		int idx = robot_order.front();
		robot_order.pop();
		idx = (idx + 1) % (2 * n);
		if (idx == n - 1)continue;
		robot_order.push(idx);
	}
}

void robot_walk(int* a, bool* robot) {
	int q_size = robot_order.size();
	for (int i = 0; i < q_size; i++) {
		int robot_idx = robot_order.front();
		robot_order.pop();
		if (robot[(robot_idx + 1) % (2 * n)] == false && a[(robot_idx + 1) % (2 * n)] >= 1) {
			a[(robot_idx + 1) % (2 * n)] -= 1;
			robot[robot_idx] = false;
			robot[(robot_idx + 1) % (2 * n)] = true;
			if ((robot_idx + 1) % (2 * n) != n - 1) {
				robot_order.push((robot_idx + 1) % (2 * n));
			}
			else {
				robot[(robot_idx + 1) % (2 * n)] = false;
			}
		}
		else {
			robot_order.push(robot_idx);
		}
	}
}

bool end_check(int* a) {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (a[i] == 0)cnt += 1;
	}

	if (cnt >= k)return true;
	return false;
}

void robot_insert(int* a, bool* robot) {
	if (robot[0] == false && a[0] >= 1) {
		robot[0] = true;
		a[0] -= 1;
		robot_order.push(0);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}

	while (true) {
		rotate(a, robot);

		robot_walk(a, robot);

		robot_insert(a, robot);

		if (end_check(a))break;
		level += 1;
	}
	cout << level;
}