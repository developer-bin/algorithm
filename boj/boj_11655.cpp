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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define ll long long
using namespace std;
string s;

char plus_13(char c) {
	for (int i = 1; i <= 13; i++) {
		if (c == 'Z')c = 'A';
		else if (c == 'z')c = 'a';
		else c += 1;
	}
	return c;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	getline(cin,s);
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == ' ') {
			cout << ' ';
		}else if('0' <= s[i] && s[i] <= '9') {
			cout << s[i];
		}
		else {
			cout << plus_13(s[i]);
		}
	}
	//print
}
