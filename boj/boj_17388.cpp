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
struct cmp {
	bool operator()(pair<string, int> a, pair<string, int> b) {
		if (a.second > b.second) {
			return true;
		}
		else return false;
	}
};
priority_queue < pair<string, int>, vector<pair<string, int>>, cmp>pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	int s, k, h,sum=0;
	cin >> s >> k >> h;
	sum = s + k + h;
	pq.push({ "Soongsil",s });
	pq.push({ "Korea",k });
	pq.push({ "Hanyang",h });
	//solve
	if (sum >= 100)cout << "OK";
	else cout << pq.top().first;
}