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
string s1, s2;
int ans1, ans2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> s1 >> s2;
	//solve
	for (int i = 0; i < (int)s1.length(); i++) {
		if (s1[i] == '6')s1[i] = '5';
	}
	for (int i = 0; i < (int)s2.length(); i++) {
		if (s2[i] == '6')s2[i] = '5';
	}
	cout << stoi(s1) + stoi(s2)<<' ';
	for (int i = 0; i < (int)s1.length(); i++) {
		if (s1[i] == '5')s1[i] = '6';
	}
	for (int i = 0; i < (int)s2.length(); i++) {
		if (s2[i] == '5')s2[i] = '6';
	}
	cout << stoi(s1) + stoi(s2) << ' ';
}