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

int a, b, c;
int n;
int max_num = MIN_VALUE;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b >> c;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		sum += (aa * a + bb * b + cc * c);
		cin >> aa >> bb >> cc;
		sum += (aa * a + bb * b + cc * c);
		cin >> aa >> bb >> cc;
		sum += (aa * a + bb * b + cc * c);

		max_num = max(max_num, sum);
	}

	cout << max_num;
}