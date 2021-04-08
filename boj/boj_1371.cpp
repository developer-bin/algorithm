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
unordered_map<char, int>maps;
int max_value = MIN_VALUE;
vector<char> v;
int c;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//init
	//input
	while ((c = getchar()) != EOF) {
		if ((char)c == ' ' || (char)c == '\n')continue;
		maps[(char)c] += 1;
	}
	//solve
	for (auto it = maps.begin(); it != maps.end(); it++) {
		if (max_value < (*it).second) {
			v.clear();
			v.push_back((*it).first);
			max_value = (*it).second;
		}
		else if (max_value == (*it).second) {
			v.push_back((*it).first);
		}
	}
	//print
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}