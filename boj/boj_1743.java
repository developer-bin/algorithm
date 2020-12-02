import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
class node{
	int x;int y;
	node(int x,int y){
		this.x=x;
		this.y=y;
	}
}
public class Main {
	static int n,m,k;
	static char maps[][]=new char[101][101];
	static boolean visit[][]=new boolean[101][101];
	static int dx[]= {0,0,-1,1};
	static int dy[]= {1,-1,0,0};
	static boolean boundary(int x,int y) {
		return x>=1 && x<=n && y>=1 && y<=m;
	}
	static int bfs(int sx,int sy) {
		int result=0;
		Queue<node> q=new LinkedList<node>();
		q.add(new node(sx,sy));
		visit[sx][sy]=true;
		while(!q.isEmpty()) {
			result+=1;
			node v=q.poll();
			for(int i=0;i<4;i++) {
				int nx=v.x+dx[i];
				int ny=v.y+dy[i];
				if(boundary(nx,ny) && visit[nx][ny]==false && maps[nx][ny]=='*') {
					visit[nx][ny]=true;
					q.add(new node(nx,ny));
				}
			}
		}
		return result;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		//BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		//StringTokenizer st;
		for(int i=1;i<=100;i++) {
			for(int j=1;j<=100;j++) {
				maps[i][j]='.';
			}
		}
		Scanner scan=new Scanner(System.in);
		//input
		n=scan.nextInt();
		m=scan.nextInt();
		k=scan.nextInt();
		for(int i=1;i<=k;i++) {
			int row,col;
			row=scan.nextInt();
			col=scan.nextInt();
			maps[row][col]='*';
		}
		//solve
		int ans=0;
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(visit[i][j]==false && maps[i][j]=='*') {
					ans=Math.max(bfs(i,j), ans);
				}
			}
		}
		//print
		System.out.println(ans);
	}
}
