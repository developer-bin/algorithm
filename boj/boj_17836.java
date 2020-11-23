import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;
class node{
	int x;int y;int gram; //그람0 그람1
	int cnt;
	node(int x,int y,int gram,int cnt){
		this.x=x;
		this.y=y;
		this.gram=gram;
		this.cnt=cnt;
	}
}
class cmp implements Comparator<node>{

	@Override
	public int compare(node a, node b) {
		if(a.cnt>=b.cnt)return -1;
		return 1;
	}
	
}
public class Main {
	final static int MAX_VALUE=200000000;
	static int n,m,t;
	static int maps[][]=new int[101][101];
	static boolean visit[][][]=new boolean[101][101][2];
	static int dx[]= {0,0,-1,1};
	static int dy[]= {1,-1,0,0};
	static int ans=MAX_VALUE;
	//static PriorityQueue<node> pq=new PriorityQueue<node>(new cmp());
	static boolean boundary(int x,int y) {
		return x>=1 && x<=n && y>=1 && y<=m;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		t=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(bf.readLine());
			for(int j=1;j<=m;j++) {
				maps[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		//solve
		Queue<node> q=new LinkedList<node>();
		q.add(new node(1,1,0,0));
		visit[1][1][0]=true;
		while(!q.isEmpty()) {
			int x=q.peek().x;
			int y=q.peek().y;
			int gram=q.peek().gram;
			int cnt=q.peek().cnt;
			q.poll();
			if(cnt>t) break;
			if(x==n && y==m) {
				ans=cnt;
				break;
			}
			for(int i=0;i<4;i++) {
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(boundary(nx,ny)) {
					if(maps[nx][ny]==2 && gram==0 && visit[nx][ny][1]==false) {
						visit[nx][ny][1]=true;
						q.add(new node(nx,ny,1,cnt+1));
					}else if(maps[nx][ny]==0 && visit[nx][ny][gram]==false) {
						visit[nx][ny][gram]=true;
						q.add(new node(nx,ny,gram,cnt+1));
					}else if(maps[nx][ny]==1 && gram==1 && visit[nx][ny][gram]==false) {
						visit[nx][ny][gram]=true;
						q.add(new node(nx,ny,gram,cnt+1));
					}
				}
			}
		}
		//print
		if(ans==MAX_VALUE)System.out.println("Fail");
		else System.out.println(ans);
	}
}
