import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
class node{
	int x;int y;int cnt;
	node(int x,int y,int cnt){
		this.x=x;
		this.y=y;
		this.cnt=cnt;
	}
}
public class Main {
	static boolean visit[][]=new boolean[251][251];
	static int maps[][]=new int[251][251];
	static int ans;
	static int n,m;
	static int dx[]= {0,0,-1,1,-1,-1,1,1};
	static int dy[]= {1,-1,0,0,-1,1,-1,1};
	static boolean boundary(int x,int y) {
		return x>=1 && x<=n && y>=1 && y<=m;
	}
	static void bfs(int sx,int sy) {
		Queue<node> q=new LinkedList<node>();
		q.add(new node(sx,sy,0));
		visit[sx][sy]=true;
		while(!q.isEmpty()) {
			node v=q.poll();
			for(int i=0;i<8;i++) {
				int nx=v.x+dx[i];
				int ny=v.y+dy[i];
				if(boundary(nx,ny) && visit[nx][ny]==false) {
					visit[nx][ny]=true;
					if(maps[nx][ny]==1) {
						q.add(new node(nx,ny,v.cnt+1));
					}
				}
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(bf.readLine());
			for(int j=1;j<=m;j++) {
				maps[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		//solve
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				if(visit[i][j]==false) {
					visit[i][j]=true;
					if(maps[i][j]==1) {
						ans+=1;
						bfs(i,j);
					}
				}
			}
		}
		//print
		System.out.println(ans);
	}
}
