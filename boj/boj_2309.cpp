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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int a[10];
bool check;
bool visit[10];
void combi(int idx, int cnt, int sum) {
	if (cnt == 7) {
		if (sum == 100) {
			for (int i = 1; i <= 9; i++) {
				if (visit[i])cout << a[i] << '\n';
			}
			check = true;
		}
		return;
	}
	for (int i = idx; i <= 9; i++) {
		visit[i] = true;
		combi(i + 1, cnt + 1, sum + a[i]);
		if (check)return;
		visit[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 9; i++)cin >> a[i];
	//solve
	sort(a + 1, a + 10);
	combi(1, 0,0);
}