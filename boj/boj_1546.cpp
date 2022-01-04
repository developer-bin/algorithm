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
int n;
vector<double> v;
double max_num = MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double num;
		cin >> num;
		v.push_back(num);
		max_num = max(max_num, num);
	}
	//solve
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] / max_num * 100;
	}
	//print
	double ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}
	cout << ans / v.size();
}
