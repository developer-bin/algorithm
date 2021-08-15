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

int n;
vector<int> v;
deque<int> dq;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	vector<int> tmp_v;
	for (int i = v.size()-1; i >=0; i--) {
		tmp_v.push_back(v[i]);
		cnt += 1;
		if (cnt == 3) {
			ans += (tmp_v[0] + tmp_v[1]);
			tmp_v.clear();
			cnt = 0;
		}
	}

	for (int i = 0; i < tmp_v.size(); i++) {
		ans += tmp_v[i];
	}

	cout << ans;
}