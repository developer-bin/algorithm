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

int question;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		string s;
		getline(cin, s);

		if (s == "고무오리 디버깅 끝")break;

		if (s == "문제")question += 1;
		else if (s == "고무오리" && question == 0)question += 2;
		else if (s == "고무오리")question -= 1;
	}

	if (question == 0)cout << "고무오리야 사랑해";
	else cout << "힝구";
}