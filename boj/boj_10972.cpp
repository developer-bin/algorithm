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
vector<int> v;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	//solve
	bool check = next_permutation(v.begin(), v.end());
	if (check == false)cout << -1;
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}
	}

}