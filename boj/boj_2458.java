
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static int m;
	static ArrayList<Integer> graph[];
	static ArrayList<Integer> r_graph[];
	static boolean visit[];
	static int ans;
	static void dfs(int v) {
		for(int i=0;i<graph[v].size();i++) {
			int to=graph[v].get(i);
			if(visit[to]==false) {
				visit[to]=true;
				dfs(to);
			}
		}
	}
	static void r_dfs(int v) {
		for(int i=0;i<r_graph[v].size();i++) {
			int to=r_graph[v].get(i);
			if(visit[to]==false) {
				visit[to]=true;
				r_dfs(to);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		//init
		graph=new ArrayList[501];
		for(int i=1;i<=500;i++) {
			graph[i]=new ArrayList<Integer>();
		}
		r_graph=new ArrayList[501];
		for(int i=1;i<=500;i++) {
			r_graph[i]=new ArrayList<Integer>();
		}
		visit=new boolean[501];
		//input
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer(bf.readLine());
		Scanner scan=new Scanner(System.in);
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=0;i<m;i++) {
			st=new StringTokenizer(bf.readLine());
			int from=Integer.parseInt(st.nextToken());
			int to=Integer.parseInt(st.nextToken());
			graph[from].add(to);
			r_graph[to].add(from);
		}
		//solve
		for(int i=1;i<=n;i++) {
			Arrays.fill(visit, false);
			visit[i]=true;
			dfs(i);
			r_dfs(i);
			boolean check=true;
			for(int j=1;j<=n;j++) {
				if(visit[j]==false) {
					check=false;
					break;
				}
			}
			if(check==true)ans+=1;
		}
		//print
		System.out.println(ans);
	}
}
