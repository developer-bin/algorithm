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
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int sum1=0, sum2=0;
		for (int i = 1; i <= 9; i++) {
			int a, b;
			cin >> a >> b;
			sum1 += a;
			sum2 += b;
		}
		if (sum1 < sum2) {
			cout << "Korea\n";
		}
		else if (sum1 > sum2) {
			cout << "Yonsei\n";
		}
		else if (sum1 == sum2) {
			cout << "Draw\n";
		}
	}
	//print
}