#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int n;
int a[2001];
int m;
int d[2001][2001];

int f(int s, int e) {
	int &ans = d[s][e];
	if (s == e)return ans =1;
	if (s + 1 == e) {
		if (a[s] == a[e])return ans =1;
		else return ans=0;
	}
	if (ans != -1)return ans;
	if (a[s] == a[e]) {
		if (f(s + 1, e - 1))return ans = 1;
		else return ans = 0;
	}
	else return ans = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	memset(d, -1, sizeof(d));
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//solve
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f(i, j);
		}
	}
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		//print
		cout << d[s][e] << '\n';
	}
}
