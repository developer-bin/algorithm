import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	final static int MIN_VALUE=-200000000;
	static int n,t;
	static int study_time[]=new int[101];
	static int grade[]=new int[101];
	static int d[][]=new int[10001][101];
	static int state(int sum,int idx) {
		if(sum==t)return 0;
		if(sum>t)return MIN_VALUE;
		if(idx>n)return 0;
		if(d[sum][idx]!=-1)return d[sum][idx];
		d[sum][idx]=Math.max(grade[idx]+state(sum+study_time[idx],idx+1), state(sum,idx+1));
		return d[sum][idx];
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		for(int i=0;i<=10000;i++) {
			for(int j=0;j<=100;j++) {
				d[i][j]=-1;
			}
		}
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		t=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(bf.readLine());
			study_time[i]=Integer.parseInt(st.nextToken());
			grade[i]=Integer.parseInt(st.nextToken());
		}
		//solve
		System.out.println(state(0,1));
		//print
	}
}
