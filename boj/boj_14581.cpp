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

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	for (int i = 1; i <= 3; i++) {
		cout << ":fan:";
	}cout << '\n';

	cout << ":fan::" << s << "::fan:\n";

	for (int i = 1; i <= 3; i++) {
		cout << ":fan:";
	}cout << '\n';
}