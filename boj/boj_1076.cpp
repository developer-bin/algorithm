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
map<string, pair<ll, ll>> maps;
string s1, s2, s3;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	maps["black"] = { 0,1 };
	maps["brown"] = { 1,10 };
	maps["red"] = { 2,100 };
	maps["orange"] = { 3,1000 };
	maps["yellow"] = { 4,10000 };
	maps["green"] = { 5,100000 };
	maps["blue"] = { 6,1000000 };
	maps["violet"] = { 7,10000000 };
	maps["grey"] = { 8,100000000 };
	maps["white"] = { 9,1000000000 };
	//input
	cin >> s1 >> s2 >> s3;
	//solve
	cout << (maps[s1].first * 10 + maps[s2].first)*maps[s3].second;
}