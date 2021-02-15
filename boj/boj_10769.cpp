#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <vector>
#include <cmath>
#include <set>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <sstream>
#define MIN_VALUE -2000000000
#define MAX_VALUE 2000000000
#define MOD 1000000000
#define ll long long
using namespace std;
string s;
int happy, sad;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	getline(cin, s);
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (i + 2 < (int)s.length() && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == ')') {
			happy += 1;
			i += 2;
		}
		else if (i + 2 < (int)s.length() && s[i] == ':' && s[i + 1] == '-' && s[i + 2] == '(') {
			sad += 1;
			i += 2;
		}
	}
	//print
	if (happy < sad) {
		cout << "sad";
	}
	else if (happy > sad) {
		cout << "happy";
	}
	else if (happy!=0 && sad!=0 && happy == sad) {
		cout << "unsure";
	}
	else if (happy == 0 && sad == 0) {
		cout << "none";
	}
}