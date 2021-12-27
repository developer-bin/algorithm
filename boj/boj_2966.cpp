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
char sang[3] = { 'A','B','C' };
char chang[4] = { 'B','A','B','C' };
char hyun[6] = { 'C','C','A','A','B','B' };
int n;
int idx_len[3] = { 3,4,6 };
string s;
int sang_cnt, chang_cnt, hyun_cnt;
int idx = 0;
bool cmp(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second)return true;
    return false;
}
vector<pair<string, int>> v;
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
        if (idx == 3)idx = 0;
        if (sang[idx] == s[i])sang_cnt += 1;
        idx += 1;
    }
    idx = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (idx == 4)idx = 0;
        if (chang[idx] == s[i])chang_cnt += 1;
        idx += 1;
    }
    idx = 0;
    for (int i = 0; i < (int)s.length(); i++) {
        if (idx == 6)idx = 0;
        if (hyun[idx] == s[i])hyun_cnt += 1;
        idx += 1;
    }
    v.push_back({ "Adrian",sang_cnt });
    v.push_back({ "Bruno",chang_cnt });
    v.push_back({ "Goran",hyun_cnt });
    sort(v.begin(), v.end(), cmp);
    int same_cnt = 1;
    for (int i = 0; i < v.size() - 1; i++) {
        if (v[i].second == v[i + 1].second)same_cnt += 1;
        else break;
    }
    cout << v[0].second << '\n';
    for (int i = 0; i < same_cnt; i++) {
        cout << v[i].first << '\n';
    }
}