import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	final static int MAX_VALUE=200000000;
	static int n,m;
	static char maps[][]=new char[51][51];
	static int ans=MAX_VALUE;
	static boolean boundary(int x,int y) {
		return x>=1 && x<=n && y>=1 && y<=m;
	}
	static char switch_c(char c) {
		if(c=='B')c='W';
		else if(c=='W')c='B';
		return c;
	}
	static int go(int s_x,int s_y,char s_c) {
		int cnt=0;
		for(int i=s_x;i<=s_x+7;i++) {
			for(int j=s_y;j<=s_y+7;j++) {
				if(maps[i][j]!=s_c) {
					cnt+=1;
				}
				s_c=switch_c(s_c);
			}
			s_c=switch_c(s_c);
		}
		return cnt;
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		for(int i=1;i<=n;i++) {
			String s=bf.readLine();
			for(int j=0;j<(int)s.length();j++) {
				maps[i][j+1]=s.charAt(j);
			}
		}
		//solve
		for(int i=1;i<=n-7;i++) {
			for(int j=1;j<=m-7;j++) {
				ans=Math.min(go(i,j,'W'), ans);
				ans=Math.min(go(i,j,'B'), ans);
			}
		}
		//print
		System.out.println(ans);
	}
}
