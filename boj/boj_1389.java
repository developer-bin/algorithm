import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	final static int MAX_VALUE=200000000;
	static int n,m;
	static int ans=MAX_VALUE;
	static int ans_man;
	static ArrayList<ArrayList<Integer>> graph=new ArrayList<ArrayList<Integer>>();
	static int bfs(int sv) {
		boolean visit[]=new boolean[101];
		visit[sv]=true;
		int dist[]=new int[101];
		Queue<Integer> q=new LinkedList<Integer>();
		q.add(sv);
		int result=0;
		while(!q.isEmpty()) {
			int v=q.poll();
			for(int i=0;i<graph.get(v).size();i++) {
				int nv=graph.get(v).get(i);
				if(visit[nv]==false) {
					visit[nv]=true;
					dist[nv]=dist[v]+1;
					result+=dist[nv];
					q.add(nv);
				}
			}
		}
		return result;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int i=1;i<=101;i++) {
			graph.add(new ArrayList<Integer>());
		}
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=1;i<=m;i++) {
			st=new StringTokenizer(bf.readLine());
			int from=Integer.parseInt(st.nextToken());
			int to=Integer.parseInt(st.nextToken());
			graph.get(from).add(to);
			graph.get(to).add(from);
		}
		//solve
		for(int i=n;i>=1;i--) {
			int result_sum=bfs(i);
			if(ans>=result_sum) {
				ans=result_sum;
				ans_man=i;
			}
		}
		//print
		System.out.println(ans_man);
	}
}
