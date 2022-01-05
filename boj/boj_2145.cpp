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

	while (true) {
		cin >> s;
		if (s == "0")break;

		while (true) {
			int num = 0;
			
			for (int i = 0; i < (int)s.length(); i++) {
				num += (s[i] - '0');
			}

			s = to_string(num);

			if ((int)s.length() == 1)break;
		}
		
		cout << s << '\n';
	}
}