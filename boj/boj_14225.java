import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int n;
	static ArrayList<Integer> v=new ArrayList<Integer>();
	static boolean visit[]=new boolean[2000001];
	static void combi(int idx,int cnt,int sum,int end_cnt) {
		if(cnt==end_cnt) {
			visit[sum]=true;
			return;
		}
		for(int i=idx;i<n;i++) {
			combi(i+1,cnt+1,sum+v.get(i),end_cnt);
		}
	}
	public static void main(String[] args) throws IOException{
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		n=Integer.parseInt(bf.readLine());
		st=new StringTokenizer(bf.readLine());
		while(st.hasMoreTokens()) {
			v.add(Integer.parseInt(st.nextToken()));
		}
		//solve
		for(int i=1;i<=n;i++) {
			combi(0,0,0,i);
		}
		//print
		for(int i=1;i<=2000000;i++) {
			if(visit[i]==false) {
				System.out.println(i);
				break;
			}
		}
		return;
	}
}
