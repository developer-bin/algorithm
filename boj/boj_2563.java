import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	static boolean visit[][]=new boolean[101][101];
	static int n;
	static int ans;
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		n=Integer.parseInt(bf.readLine());
		for(int i=1;i<=n;i++) {
			st=new StringTokenizer(bf.readLine());
			int x=0,y=0;
			x=Integer.parseInt(st.nextToken());
			y=Integer.parseInt(st.nextToken());
			for(int xx=x;xx<x+10;xx++) {
				for(int yy=y;yy<y+10;yy++) {
					visit[xx][yy]=true;
				}
			}
		}
		//solve
		for(int i=0;i<100;i++) {
			for(int j=0;j<100;j++) {
				if(visit[i][j]==true) {
					ans+=1;
				}
			}
		}
		//print
		System.out.println(ans);
	}
}
