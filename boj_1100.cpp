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
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;
char maps[9][9];
int c;
int cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf(" %c", &maps[i][j]);
		}
	}
	//solve
	for (int i = 1; i <= 8; i++) {
		c = 1 - c;
		for (int j = 1; j <= 8; j++) {
			if (c == 1 && j % 2 == 1 && maps[i][j] == 'F') cnt += 1;
			if (c == 0 && j % 2 == 0 && maps[i][j] == 'F')cnt += 1;
		}
	}
	cout << cnt;
}