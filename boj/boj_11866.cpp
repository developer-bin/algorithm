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
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	cout << "<";
	int cnt = 1;
	while (!q.empty()) {
		if (cnt == k) {
			if (q.size() == 1) {
				cout << q.front() << ">";
			}
			else {
				cout << q.front() << ", ";
			}
			q.pop();
			cnt = 1;
			continue;
		}
		q.push(q.front());
		q.pop();
		cnt += 1;
	}
}