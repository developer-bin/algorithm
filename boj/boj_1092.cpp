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
#include <list>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n, m;
int ans;
vector<int> sort_box;
vector<int> crain;
list<int> box;
using namespace std;
bool cmp(int a, int b) {
	if (a > b)return true;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		crain.push_back(num);
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		sort_box.push_back(num);
	}
	//solve
	sort(crain.begin(), crain.end(), cmp);
	sort(sort_box.begin(), sort_box.end(), cmp);
	for (int i = 0; i < sort_box.size(); i++) {
		box.push_back(sort_box[i]);
	}
	while (true) {
		if (box.empty() == true)break;
		list<int>::iterator it = box.begin();
		bool check = false;
		int crain_idx = 0;
		while (true) {
			if (box.empty() == true)break;
			if (crain_idx == n)break;
			if (it == box.end())break;
			if (*(it) <= crain[crain_idx]) {
				check = true;
				list<int>::iterator next_it = ++it;
				it--;
				box.erase(it);
				it = next_it;
				crain_idx += 1;
			}
			else {
				it++;
			}
		}
		if (check) {
			ans += 1;
		}
		else {
			ans = -1;
			break;
		}
	}
	//print
	cout << ans;
}