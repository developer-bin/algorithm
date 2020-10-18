#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int n;
int cnt[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		cnt[num] += 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] == 0)continue;
		for (int j = 1; j <= cnt[i]; j++) {
			cout << i << '\n';
		}
	}
}