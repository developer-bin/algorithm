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

queue<char> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		cin >> s;
		if (s == "#")break;

		for (int i = 0; i < (int)s.length(); i++) {
			q.push(s[i]);
		}

		int q_size = q.size();

		while (q_size--) {
			if (q.front() == 'a' || q.front() == 'e' || q.front() == 'i' || q.front() == 'o' || q.front() == 'u') {
				break;
			}

			q.push(q.front());
			q.pop();
		}

		string ans_s;

		while (!q.empty()) {

			ans_s += q.front(); q.pop();

		}

		cout << ans_s << "ay\n";

	}
}