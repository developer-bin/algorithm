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
#define MOD 9901
#define ll long long
using namespace std;

struct vertex {
	int s_time; int stud_num; int recommand;
};
vector<vertex>v;
int n;
int m;
bool cmp(vertex a, vertex b) {
	return a.stud_num < b.stud_num;
}
bool matter_2_cmp(vertex a, vertex b) {
	if (a.recommand > b.recommand)return true;
	else if (a.recommand == b.recommand) {
		if (a.s_time > b.s_time)return true;
	}
	return false;
}
bool visit[101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//init
	//input
	cin >> n;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int num;
		cin >> num;
		if (v.size() == n) {
			if (visit[num] == false) {
				sort(v.begin(), v.end(), matter_2_cmp);
				visit[v[v.size() - 1].stud_num]=false;
				v[v.size() - 1] = { i,num,1 };
				visit[num] = true;
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					if (v[i].stud_num == num) { v[i].recommand += 1; break; }
				}
			}
		}
		else if(v.size()<n){
			if (visit[num] == false) {
				v.push_back({ i,num,1 });
				visit[num] = true;
			}
			else {
				for (int i = 0; i < v.size(); i++) {
					if (v[i].stud_num == num) { v[i].recommand += 1; break; }
				}
			}
		}
	}
	sort(v.begin(), v.end(),cmp);
	for (auto k : v) {
		cout << k.stud_num << ' ';
	}
}