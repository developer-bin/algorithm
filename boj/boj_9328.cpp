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
		//�׵θ������� ���� �������ְ�
		for (int i = 1; i <= n+2; i++) {
			for (int j = 1; j <= m+2; j++) {
				map[i][j] = '.';
			}
		}
		//�׵θ��� �ʱ׸���
		for (int i = 2; i <= n + 1; i++) {
			for (int j = 2; j <= m + 1; j++) {
				scanf(" %c", &map[i][j]);
			}
		}
		//Ű �ָӴϿ� ����
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
					//�������̰� �ѹ��� �̻��¸� �湮��������
					if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
						//�������°� ���̰�
						if (key[map[nx][ny] - 'A']) {
							//�׹��� �ش��ϴ� Ű��������
							//��
							visit[nx][ny] = true;
							map[nx][ny] = '.';
							q.push({ nx,ny });
						}
					}
					if (map[nx][ny] == '.') {
						//�׳� �ٴ��϶� ����
						visit[nx][ny] = true;
						q.push({ nx,ny });
					}
					if (map[nx][ny] == '$') {
						//�����϶� ���������ø��� ����
						map[nx][ny] = '.';
						visit[nx][ny] = true;
						ans += 1;
						q.push({ nx,ny });
					}
					if ('a' <= map[nx][ny] && map[nx][ny] <= 'z') {
						//Ű�ٴڿ��ִµ� �̹� ����Ű ������������ �׳� �ɾ
						if (key[map[nx][ny] - 'a']) {
							visit[nx][ny] = true;
							map[nx][ny] = '.';
							q.push({ nx,ny });
						}
						else {
							//Ű�� �ٴڿ������� Ű���� �׸��� �ű⼭ �������ؾߵ�
							//�׷����� Ű��� �����Ӵ��� ���������� ��������
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