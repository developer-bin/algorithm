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
int a_cnt;
int b_cnt;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	cin >> s;
	//solve
	for (int i = 0; i < (int)s.length(); i++) {
		if (s[i] == 'A')a_cnt += 1;
		else if (s[i] == 'B')b_cnt += 1;
	}
	//print
	if (a_cnt > b_cnt)cout << 'A';
	else if (a_cnt < b_cnt)cout << 'B';
	else cout << "Tie";
}