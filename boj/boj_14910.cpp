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

vector<int> v;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (cin >> n) {
		v.push_back(n);
	}

	bool check = true;
	
	for (int i = 0; i < v.size() - 1; i++) {
		if(v[i]>v[i+1]){
			check = false;
			break;
		}
	}

	if (check)cout << "Good";
	else cout << "Bad";
}