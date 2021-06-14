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
int k, d, a;
string s;
string slice_s;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> s;
	stringstream ss(s);
	getline(ss, slice_s, '/');
	k = stoi(slice_s);
	getline(ss, slice_s, '/');
	d = stoi(slice_s);
	getline(ss, slice_s, '/');
	a = stoi(slice_s);
	//solve
	if (k + a < d || d == 0)cout << "hasu";
	else cout << "gosu";
	//print
}