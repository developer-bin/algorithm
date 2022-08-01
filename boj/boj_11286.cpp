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

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first) {
			return true;
		}
		else if (a.first == b.first) {
			if (a.second > b.second)return true;
		}
		return false;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>pq;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty() == true) {
				cout << 0 << "\n";
				continue;
			}
			auto top_pair = pq.top();
			pq.pop();
			if (top_pair.second == 1) {
				cout << top_pair.first << '\n';
			}
			else{
				cout << top_pair.first * (-1) << '\n';
			}
		}
		else if(x<0){
			pq.push({ x*(-1),-1 });
		}
		else if (x > 0) {
			pq.push({ x,1 });
		}
	}
	//print
}
