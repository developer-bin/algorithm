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
int t;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	//solve
	while (true) {
		cin >> n;
		if (n == -1)break;
		vector<int> v;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				v.push_back(i);
				sum += i;
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < v.size()-1; i++) {
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] << '\n';
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
	}
	//print
}
