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
int q1, q2, q3, q4, axis;
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	//solve
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > 0 && y > 0) {
			q1 += 1;
		}
		else if (x < 0 && y>0) {
			q2 += 1;
		}
		else if (x < 0 && y < 0) {
			q3 += 1;
		}
		else if (x > 0 && y < 0) {
			q4 += 1;
		}
		else if (x==0 || y==0){
			axis += 1;
		}
	}
	//print
	cout << "Q1: " << q1 << "\n" << "Q2: " << q2 << "\n" << "Q3: " << q3 << "\n" << "Q4: " << q4 << "\n" << "AXIS: " << axis;
}