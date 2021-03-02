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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
int check[31];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 28; i++) {
		int num;
		cin >> num;
		check[num] = true;
	}
	//solve
	for (int i = 1; i <= 30; i++) {
		if (check[i] == false)cout << i << '\n';
	}
	//print
	return 0;
}