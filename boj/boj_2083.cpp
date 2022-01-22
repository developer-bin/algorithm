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

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		int age;
		int weight;

		cin >> s >> age >> weight;

		if (s=="#" && age == 0 && weight == 0)break;

		if (age > 17 || weight >= 80) {
			cout << s << ' ' << "Senior\n";
		}
		else {
			cout << s << ' ' << "Junior\n";
		}
	}
}