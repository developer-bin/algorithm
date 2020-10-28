import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	final static int MIN_VALUE=-200000000;
	static int sum[]=new int[101];
	static int n,m;
	static int d[][]=new int[101][51];
	static boolean boundary(int x) {
		return x>=1 && x<=n;
	}
	static int state(int idx,int cnt) {
		if(m==cnt)return 0;
		if(idx>=n+1)return MIN_VALUE;
		if(d[idx][cnt]!=-1)return d[idx][cnt];
		int diff=0;
		d[idx][cnt]=MIN_VALUE;
		while(true) {
			if(boundary(idx+diff)) {
				d[idx][cnt]=Math.max(d[idx][cnt], (sum[idx+diff]-sum[idx-1])+state(idx+diff+2,cnt+1));
			}else break;
			diff+=1;
		}
		d[idx][cnt]=Math.max(d[idx][cnt], state(idx+1,cnt));
		return d[idx][cnt];
	}
	public static void main(String[] args) throws IOException{
		//init
		for(int i=0;i<=100;i++) {
			for(int j=0;j<=50;j++) {
				d[i][j]=-1;
			}
		}
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			int num=Integer.parseInt(bf.readLine());
			sum[i]=sum[i-1]+num;
		}
		//solve
		System.out.println(state(1,0));
		//print
	}
}
