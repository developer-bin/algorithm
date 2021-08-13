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

int n;

ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a,b;
        cin>>a>>b;
        cout<<(a*b)/gcd(a,b)<<'\n';
    }
}
