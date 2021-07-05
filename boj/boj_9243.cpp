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
string s1, s2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> n;
	cin >> s1 >> s2;
	//solve
	if (n % 2 == 0) {
		if (s1 == s2)cout << "Deletion succeeded";
		else cout << "Deletion failed";
	}
	else {
		bool check = true;
		for (int i = 0; i < (int)s1.length(); i++) {
			if (s1[i] == s2[i]) {
				check = false;
				break;
			}
		}
		if (check) {
			cout << "Deletion succeeded";
		}
		else {
			cout << "Deletion failed";
		}
	}
}