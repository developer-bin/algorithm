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
int k;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> k;
	for (int t = 1; t <= k; t++) {
		cin >> n;
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());
		int gap = MIN_VALUE;
		for (int i = 0; i < v.size() - 1; i++) {
			gap = max(gap, v[i + 1] - v[i]);
		}
		cout << "Class " << t << '\n' << "Max " << v.back() << ", Min " << v.front() << ", Largest gap " << gap << '\n';
	}
	//solve
	//print
	return 0;
}