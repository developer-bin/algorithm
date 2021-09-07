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

struct cmp {
	bool operator()(int a, int b) {
		if (a < b)return true;
		return false;
	}
};

priority_queue<int, vector<int>, cmp>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int num;
		
		for (int i = 1; i <= 3; i++) {
			cin >> num;
			pq.push(num);
		}

		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int c = pq.top(); pq.pop();

		if (a == 0 && b == 0 && c == 0)break;

		if (a >= b + c)cout << "Invalid\n";
		else if (a == b && a == c && b == c)cout << "Equilateral\n";
		else if (a == b || a == c || b == c)cout << "Isosceles\n";
		else if (a != b && a != c && b != c)cout << "Scalene\n";
	}
}