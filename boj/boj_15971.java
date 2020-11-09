import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class node{
	int to;
	int cost;
	node(int to,int cost){
		this.to=to;
		this.cost=cost;
	}
}
public class Main {
	final static int MAX_VALUE=2000000000;
	static int n,a,b;
	static int dist_a[]=new int[100001];
	static int dist_b[]=new int[100001];
	static boolean visit[]=new boolean[100001];
	static ArrayList<node> graph_v[]=new ArrayList[100001];
	static int ans=MAX_VALUE;
	static void dfs_a(int v,int cost) {
		dist_a[v]=cost;
		for(int i=0;i<graph_v[v].size();i++) {
			int n_v=graph_v[v].get(i).to;
			int n_cost=graph_v[v].get(i).cost;
			if(visit[n_v]==false) {
				visit[n_v]=true;
				dfs_a(n_v,cost+n_cost);
			}
		}
	}
	static void dfs_b(int v,int cost) {
		dist_b[v]=cost;
		for(int i=0;i<graph_v[v].size();i++) {
			int n_v=graph_v[v].get(i).to;
			int n_cost=graph_v[v].get(i).cost;
			if(visit[n_v]==false) {
				visit[n_v]=true;
				dfs_b(n_v,cost+n_cost);
			}
		}
	}
	public static void main(String[] args) throws IOException{
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int i=1;i<=100000;i++) {
			graph_v[i]=new ArrayList<node>();
		}
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		a=Integer.parseInt(st.nextToken());
		b=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n-1;i++) {
			st=new StringTokenizer(bf.readLine());
			int from=Integer.parseInt(st.nextToken());
			int to=Integer.parseInt(st.nextToken());
			int cost=Integer.parseInt(st.nextToken());
			graph_v[from].add(new node(to,cost));
			graph_v[to].add(new node(from,cost));
		}
		//solve
		if(n==1 || (a==b)) {
			System.out.println(0);
			return;
		}
		visit[a]=true;
		dfs_a(a,0);
		Arrays.fill(visit, false);
		visit[b]=true;
		dfs_b(b,0);
		for(int i=1;i<=n;i++) {
			for(int j=0;j<graph_v[i].size();j++) {
				int from=i;
				int to=graph_v[i].get(j).to;
				ans=Math.min(ans, dist_a[from]+dist_b[to]);
				ans=Math.min(ans, dist_a[to]+dist_b[from]);
			}
		}
		//print
		System.out.println(ans);
		return;
	}

}
