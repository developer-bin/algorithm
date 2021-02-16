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
struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first)return true;
		return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 9; i++) {
		int num;
		cin >> num;
		pq.push({ num,i });
	}
	//solve
	//print
	cout << pq.top().first << '\n' << pq.top().second;
}