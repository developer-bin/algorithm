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
int n;
int zero, one;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		if (num == 0)zero += 1;
		else if (num == 1)one += 1;
	}
	//print
	if (zero > one) {
		cout << "Junhee is not cute!";
	}
	else if (zero < one) {
		cout << "Junhee is cute!";
	}
}