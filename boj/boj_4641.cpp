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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	while (true) {
		int ans = 0;
		int num;
		cin >> num;
		if (num == -1)break;
		vector<int> v;
		v.push_back(num);
		while (true) {
			int num;
			cin >> num;
			if (num == 0)break;
			v.push_back(num);
		}
		for (int i = 0; i < v.size() - 1; i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if (v[i] * 2 == v[j] || v[i] == v[j] * 2) {
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	//solve
	//print
	return 0;
}