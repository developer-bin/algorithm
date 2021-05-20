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
int t;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	cin >> t;
	//solve
	while (t--) {
		int num;
		cin >> num;
		for (int i = 1; i <= num; i++) {
			if (i == 1 || i == num) {
				for (int j = 1; j <= num; j++) {
					cout << '#';
				}cout << '\n';
			}
			else {
				cout << '#';
				for (int j = 1; j <= num - 2; j++) {
					cout << 'J';
				}cout << "#\n";
			}
		}cout << '\n';
	}
	//print
}