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
int k;
int p, m;
bool chair[501];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> k;
	while (k--) {
		memset(chair, false, sizeof(chair));
		cin >> p >> m;
		int no_sit = 0;
		for (int i = 1; i <= p; i++) {
			int num;
			cin >> num;
			if (chair[num] == false)chair[num] = true;
			else no_sit += 1;
		}
		cout << no_sit << '\n';
	}
	//solve
}