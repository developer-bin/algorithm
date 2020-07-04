package baek;

import java.util.Scanner;

public class boj_14503 {
	static int n,m;
	static int maps[][]=new int[51][51];
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	static int sx,sy,dist;
	static boolean visit[][]=new boolean[51][51];
	static int ans;
	static boolean exit;
	static int test[][]=new int[51][51];
	static int cnt=1;
	public static void main(String[] args) {
		//init
		//input
		Scanner scan=new Scanner(System.in);
		n=scan.nextInt();
		m=scan.nextInt();
		sx=scan.nextInt();
		sx+=1;
		sy=scan.nextInt();
		sy+=1;
		dist=scan.nextInt();
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				maps[i][j]=scan.nextInt();
			}
		}
		//solve
		visit[sx][sy]=true;
		test[sx][sy]=cnt++;
		ans+=1;
		state(sx,sy,dist);
		System.out.println(ans);
	}
	static int next_dist(int dist) {
		if(dist==0)return 3;
		else if(dist==1)return 0;
		else if(dist==2)return 1;
		else return 2;
	}
	static boolean boundary(int x,int y) {
		return x>=1 && x<=n && y>=1 && y<=m;
	}
	static int back_dist(int dist) {
		if(dist==0)return 2;
		else if(dist==1)return 3;
		else if(dist==2)return 0;
		else return 1;
	}
	static void state(int x,int y,int dist) {
		int n_dist = dist;
		for(int i=0;i<4;i++) {
			n_dist=next_dist(n_dist);
			int nx=x+dx[n_dist];
			int ny=y+dy[n_dist];
			if(boundary(nx,ny) && visit[nx][ny]==false && maps[nx][ny]==0) {
				visit[nx][ny]=true;
				ans+=1;
				test[nx][ny]=cnt++;
				state(nx,ny,n_dist);
				return;
			}
		}
		int b_dist = back_dist(dist);
		int nx = x + dx[b_dist];
		int ny = y + dy[b_dist];
		if (boundary(nx, ny) && maps[nx][ny] == 0) {
			state(nx, ny, dist);
			if(exit)return;
		}else {
			exit=true;
			return;
		}
	}
}
