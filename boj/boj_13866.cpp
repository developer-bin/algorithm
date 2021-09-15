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

vector<int> v;
int min_num = MAX_VALUE;

void state(int a, int b) {
	int sum1 = v[a] + v[b];
	int sum2 = 0;
	
	for (int i = 0; i < 4; i++) {
		if (i == a || i == b)continue;
		sum2 += v[i];
	}

	min_num = min(min_num, abs(sum2 - sum1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 4; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			state(i, j);
		}
	}

	cout << min_num;
}