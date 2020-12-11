import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;
public class Main {
	static int n,d,k,c;
	static int a[]=new int[3000001];
	static int visit[]=new int[3001];
	static int ans;
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//Scanner scan=new Scanner(System.in);
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		d=Integer.parseInt(st.nextToken());
		k=Integer.parseInt(st.nextToken());
		c=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			a[i]=Integer.parseInt(bf.readLine());
		}
		//solve
		for(int i=1;i<=k;i++) {
			visit[a[i]]+=1;
		}
		for(int i=1;i<=d;i++) {
			if(visit[i]>=1) {
				ans+=1;
			}
		}
		int sum=ans;
		if(visit[c]==0)ans+=1;
		for(int i=k+1;i<=n+k-1;i++) {
			int r_idx=i;
			int l_idx=i-k;
			if(r_idx>n) {
				r_idx=i-n;
			}
			visit[a[l_idx]]-=1;
			if(visit[a[l_idx]]==0)sum-=1;
			if(visit[a[r_idx]]==0)sum+=1;
			visit[a[r_idx]]+=1;
			if(visit[c]==0) {
				ans=Math.max(sum+1, ans);
			}else {
				ans=Math.max(sum, ans);
			}
		}
		//print
		System.out.println(ans);
	}
}
