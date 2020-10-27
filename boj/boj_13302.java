import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Main {
	static final int MAX_VALUE=200000000;
	static int n,m;
	static boolean visit[]=new boolean[101];
	static int ans=MAX_VALUE;
	static int d[][]=new int[111][100001];
	static int state(int idx,int ticket) {
		if(idx>=n+1) {
			return 0;
		}
		if(d[idx][ticket]!=-1)return d[idx][ticket];
		d[idx][ticket]=MAX_VALUE;
		if(visit[idx]==true) {
			//ArrayList<Integer> min_list=new ArrayList<>();
			d[idx][ticket]=Math.min(Math.min(state(idx+1,ticket)+10000, state(idx+3,ticket+1)+25000),state(idx+5,ticket+2)+37000);
			if(ticket>=3) {
				d[idx][ticket]=Math.min(d[idx][ticket], state(idx+1,ticket-3));
			}
		}else {
			d[idx][ticket]=state(idx+1,ticket);
		}
		return d[idx][ticket];
	}
	public static void main(String[] args) throws IOException{
		//init
		for(int i=1;i<=110;i++) {
			for(int j=0;j<=100000;j++) {
				d[i][j]=-1;
			}
		}
		Arrays.fill(visit, true);
		Scanner scan=new Scanner(System.in);
		//input
		n=scan.nextInt();
		m=scan.nextInt();
		for(int i=1;i<=m;i++) {
			int idx=scan.nextInt();
			visit[idx]=false;
		}
		//solve
		//print
		System.out.println(state(1,0));
	}
}
