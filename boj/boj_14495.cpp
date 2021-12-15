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

int d[117];
int n;

int f(int n) {
	if (n == 1 || n == 2 || n == 3)return d[n]=1;

	int& result = d[n];
	if (result != -1)return result;

	return result = f(n - 1) + f(n - 3);

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(d, -1, sizeof(d));

	cin >> n;

	cout << f(n);
}