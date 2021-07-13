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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		string slice_s;
		vector<string> v;
		while (getline(ss, slice_s, ' ')) {
			v.push_back(slice_s);
		}
		cout << "Case #" << i << ": ";
		for (int i = v.size() - 1; i >= 0; i--) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	//solve
}