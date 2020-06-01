#include <iostream>
using namespace std;
int a, b, v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//input
	cin >> a >> b >> v;
	//solve
	int mok = (v - a) / (a - b);
	int na = (v - a) % (a - b);
	if (na == 0)mok += 1;
	else mok += 2;
	cout << mok;
}