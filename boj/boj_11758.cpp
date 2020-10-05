#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
using namespace std;
int ccw(int x1, int y1, int x2, int y2,int x3,int y3) {
	int result= x1 * y2 + x2 * y3 + x3 * y1 - (x1*y3 + x2 * y1 + x3 * y2);
	if (result == 0)return 0;
	else if (result < 0)return -1;
	else return 1;
}
int main() {
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	cout << ccw(x1, y1, x2, y2, x3, y3);
}