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
int a[10];
vector<int> v;
bool check = false;
void combi(int idx, int cnt) {
	if (cnt == 7) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i];
		}
		if (sum == 100) {
			for (int i : v) {
				cout << i << '\n';
			}
			check = true;
		}
		return;
	}
	for (int i = idx; i <= 9; i++) {
		v.push_back(a[i]);
		combi(i + 1, cnt + 1);
		if (check)return;
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 9; i++) {
		cin >> a[i];
	}
	//solve
	combi(1, 0);
	//print

}