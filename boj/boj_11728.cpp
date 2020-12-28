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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
priority_queue<int, vector<int>, cmp>pq;
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	for (int i = 1; i <= n + m; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}
	//solve
	//print
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
}