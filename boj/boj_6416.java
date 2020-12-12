import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
public class Main {
	final static int MAX_INDEX=100000;
	static int cnt=0;
	static void dfs(int v,ArrayList<ArrayList<Integer>> graph,boolean visit[]) {
		visit[v]=true;
		cnt+=1;
		for(int i=0;i<graph.get(v).size();i++) {
			int n_v=graph.get(v).get(i);
			if(visit[n_v]==false) {
				dfs(n_v,graph,visit);
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		Scanner scan=new Scanner(System.in);
		//input
		int case_num=1;
		while(true) {
			int in_d[]=new int[MAX_INDEX];
			int out_d[]=new int[MAX_INDEX];
			ArrayList<ArrayList<Integer>> graph=new ArrayList<ArrayList<Integer>>(MAX_INDEX);
			for(int i=0;i<MAX_INDEX;i++) {
				graph.add(new ArrayList<Integer>());
			}
			HashSet<Integer> sets=new HashSet<Integer>();
			int from=0,to=0;
			while(true) {
				from=scan.nextInt();
				to=scan.nextInt();
				if(from==0 && to==0)break;
				if(from==-1 && to==-1)return;
				in_d[to]+=1;
				out_d[from]+=1;
				sets.add(from);
				sets.add(to);
				graph.get(from).add(to);
			}
			if(sets.size()==0 && from==0 && to==0) {
				System.out.println("Case "+case_num+" is a tree.");
				case_num+=1;
				continue;
			}
			boolean check=false;
			int root = 0;
			boolean tree_check=true;
			Iterator<Integer> it=sets.iterator();
			while(it.hasNext()) {
				int i=it.next();
				if(in_d[i]==0 && check==true) {
					tree_check=false;
					break;
				}
				if(in_d[i]==0 && check==false) {
					check=true;
					root=i;
				}
				if(in_d[i]>=2) {
					tree_check=false;
					break;
				}
			}
			if(tree_check==false || check==false) {
				System.out.println("Case "+case_num+" is not a tree.");
				case_num+=1;
				continue;
			}
			boolean visit[]=new boolean[MAX_INDEX];
			cnt=0;
			dfs(root,graph,visit);
			if(cnt==sets.size()) {
				System.out.println("Case "+case_num+" is a tree.");
				case_num+=1;
			}else {
				System.out.println("Case "+case_num+" is not a tree.");
				case_num+=1;
			}
		}
		//solve
		//print
	}
}
