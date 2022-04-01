#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;
char map[102][102];
bool visit[102][102];
int n, m,t;
bool key[26];
char key_a[27];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans;

struct v {
	int x; int y;
};
bool boundary(int x, int y) {
	return x >= 1 && x <= n + 2 && y >= 1 && y <= m + 2;
}
int main() {

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		//테두리를위해 모든맵 걸을수있게
		for (int i = 1; i <= n+2; i++) {
			for (int j = 1; j <= m+2; j++) {
				map[i][j] = '.';
			}
		}
		//테두리안 맵그리기
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= m + 1; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		//키 주머니에 넣음
		memset(key, false, sizeof(key));
		scanf(" %s", key_a);
		int key_len = strlen(key_a);
		if (key_a[0] != '0') {
			for (int i = 0; i < key_len; i++) {
				key[key_a[i] - 'a'] = true;
			}
		}
		queue<v> q;
		q.push({ 1,1 });
		memset(visit, false, sizeof(visit));
		visit[1][1] = true;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (boundary(nx, ny) && visit[nx][ny]==false) {
					//범위안이고 한번도 이상태를 방문안햇을때
					if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
						//다음상태가 문이고
						if (key[map[nx][ny] - 'A']) {
							//그문에 해당하는 키가있을때
							//들어감
							visit[nx][ny] = true;
							map[nx][ny] = '.';
							q.push({ nx,ny });
						}
					}
					if (map[nx][ny] == '.') {
						//그냥 바닥일땐 전진
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
					if (map[nx][ny] == '$') {
						//문서일때 문서개수늘리고 전진
						map[nx][ny] = '.';
						visit[nx][ny] = true;
						ans += 1;
						q.push({ nx,ny });
					}
					if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
						//키바닥에있는데 이미 같은키 가지고있을때 그냥 걸어감
						if (key[map[nx][ny] - 'a']) {
							visit[nx][ny] = true;
							map[nx][ny] = '.';
							q.push({ nx,ny });
						}
						else {
							//키가 바닥에있을때 키주음 그리고 거기서 새시작해야됨
							//그래야지 키없어서 예전왓던문 못열었던거 열수잇음
							while (!q.empty())q.pop();
							memset(visit, false, sizeof(visit));
							visit[nx][ny] = true;
							key[map[nx][ny] - 'a'] = true;
							map[nx][ny] = '.';
							q.push({ nx,ny });
						}
					}
				}
			}
		}
		printf("%d\n", ans);
		ans = 0;
	}
	return 0;
}