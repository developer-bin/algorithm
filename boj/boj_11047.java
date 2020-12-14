import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n,k;
	static int a[]=new int[11];
	static int ans;
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		k=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			a[i]=Integer.parseInt(bf.readLine());
		}
		//solve
		for(int i=n;i>=1;i--) {
			if(k==0)break;
			if(k/a[i]>=1) {
				ans+=k/a[i];
				k%=a[i];
			}
		}
		//print
		System.out.println(ans);
	}
}
