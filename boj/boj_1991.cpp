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
#include <unordered_set>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
map<char, pair<char, char>> graph;
int n;

void pri_dfs(char alpha) {
	cout << alpha;
	char left = graph[alpha].first;
	char right = graph[alpha].second;
	if (left != '.')pri_dfs(left);
	if (right != '.')pri_dfs(right);
}
void in_dfs(char alpha) {
	char left = graph[alpha].first;
	char right = graph[alpha].second;
	if (left != '.')in_dfs(left);
	cout << alpha;
	if (right != '.')in_dfs(right);
}
void post_dfs(char alpha) {
	char left = graph[alpha].first;
	char right = graph[alpha].second;
	if (left != '.')post_dfs(left);
	if (right != '.')post_dfs(right);
	cout << alpha;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		char from, to1, to2;
		cin >> from >> to1 >> to2;
		graph[from].first = to1;
		graph[from].second = to2;
	}
	//solve
	pri_dfs('A');
	cout << '\n';
	in_dfs('A');
	cout << '\n';
	post_dfs('A');
}