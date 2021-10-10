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
int n;
string s;
int num;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		num = MIN_VALUE;
		
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int tmp_num;
			string tmp_s;

			cin >> tmp_num;
			cin >> tmp_s;

			if (num < tmp_num) {
				num = tmp_num;
				s = tmp_s;
			}
		}

		cout << s << '\n';
	}
}