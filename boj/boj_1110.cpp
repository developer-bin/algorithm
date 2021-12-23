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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 1000000000
#define ll long long
using namespace std;
int n;

int slice_and_add(string s) {

	if (s.length() == 1) {
		s.push_back(s[0]);
		s[0] = '0';
	}
	int s_len = s.length();
	int sum = 0;
	for (int i = 0; i < s_len; i++) {
		sum += (s[i] - '0');
	}
	string tmp_s = to_string(sum);
	int tmp_s_len = tmp_s.length();
	char left_s = s[s_len - 1];
	char right_s = tmp_s[tmp_s_len - 1];
	string result_s;
	result_s.push_back(left_s);
	result_s.push_back(right_s);
	return stoi(result_s);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> n;
	//solve
	string s = to_string(n);
	string ori_s = s;
	int cnt = 0;
	while (true) {
		cnt += 1;
		int result = slice_and_add(s);
		string result_s = to_string(result);
		if (result_s == ori_s)break;
		s = result_s;
	}
	//print
	cout << cnt;
}