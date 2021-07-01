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
string sum_s;
int sum;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //init
    //input
    //solve
    while (true) {
        getline(cin, s);
        if (cin.eof() == true)break;
        sum_s += s;
    }
    stringstream ss(sum_s);
    string split_s;
    while (getline(ss, split_s, ',')) {
        sum += stoi(split_s);
    }
    cout << sum;
}