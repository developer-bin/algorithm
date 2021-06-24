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
int n, m;
int num = 1;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n >> m;
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j == m)cout << num++;
			else cout << num++ << ' ';
		}
		cout << '\n';
	}
}