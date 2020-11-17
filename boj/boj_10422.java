import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	final static int MOD=1000000007;
	static int t,n;
	static int[][] d=new int[2501][2501];
	static int state(int l_cnt,int r_cnt) {
		if(l_cnt<r_cnt)return 0;
		if(l_cnt<0 || r_cnt<0)return 0;
		if(l_cnt==0 && r_cnt==0)return 1;
		if(d[l_cnt][r_cnt]!=-1)return d[l_cnt][r_cnt];
		d[l_cnt][r_cnt]=state(l_cnt-1,r_cnt)%MOD+state(l_cnt,r_cnt-1)%MOD;
		return d[l_cnt][r_cnt]%=MOD;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int i=0;i<=2500;i++) {
			for(int j=0;j<=2500;j++) {
				d[i][j]=-1;
			}
		}
		//input
		t=Integer.parseInt(bf.readLine());
		while(t--!=0) {
			n=Integer.parseInt(bf.readLine());
			if(n%2==1)System.out.println(0);
			else System.out.println(state(n/2,n/2));
		}
	}
}
