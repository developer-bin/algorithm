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
#define MIN_VALUE -200000000
#define MAX_VALUE 200000000
#define MOD 9901
#define ll long long
using namespace std;
int t;
char maps[6][10];
int pin;
int ans_pin=MAX_VALUE, ans_move=MAX_VALUE;
bool boundary(int x, int y) {
	return x >= 1 && x <= 5 && y >= 1 && y <= 9;
}
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int pin,int move) {
	if (ans_pin > pin) {
		ans_pin = pin;
		ans_move = move;
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (maps[i][j] == 'o') {
				for (int d = 0; d < 4; d++) {
					int nx = i + dx[d];
					int ny = j + dy[d];
					int nnx = nx + dx[d];
					int nny = ny + dy[d];
					if (boundary(nx, ny) && boundary(nnx, nny) && maps[nx][ny] == 'o' && maps[nnx][nny] == '.') {
						maps[nx][ny] = '.';
						maps[nnx][nny] = 'o';
						maps[i][j] = '.';
						dfs(pin - 1, move + 1);
						maps[nx][ny] = 'o';
						maps[nnx][nny] = '.';
						maps[i][j] = 'o';
					}
				}
			}
		}
	}
}
int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	//init
	//input
	cin >> t;
	while (t--) {
		pin = 0;
		for (int i = 1; i <= 5; i++) {
			for (int j = 1; j <= 9; j++) {
				scanf(" %c", &maps[i][j]);
				if (maps[i][j] == 'o')pin += 1;
			}
		}
		//solve
		ans_pin = MAX_VALUE; ans_move = MAX_VALUE;
		dfs(pin, 0);
		cout << ans_pin << ' ' << ans_move << '\n';
	}
}