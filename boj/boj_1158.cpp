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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n, k;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//solve
	cout << '<';
	int cnt = 1;
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (cnt == k) {
			cout << num;
			cnt = 1;
			if (q.empty() == false) {
				cout << ", ";
			}
			continue;
		}
		cnt += 1;
		q.push(num);
	}
	cout << '>';
	//print
}