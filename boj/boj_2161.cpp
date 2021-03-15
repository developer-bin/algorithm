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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
queue<int> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	//solve
	while (q.size() != 1) {
		cout << q.front() << ' ';
		q.pop();
		int front = q.front();
		q.pop();
		q.push(front);
	}
	//print
	cout << q.front();
}