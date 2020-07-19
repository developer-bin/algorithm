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
struct cmp {
	bool operator()(int a, int b) {
		if (a > b)return true;
		return false;
	}
};
priority_queue<int, vector<int>, cmp> pq;
int t;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	while (t--) {
		cin >> n;
		//solve
		if (n == 0) {
			if (pq.empty() == true) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(n);
		}
	}

}