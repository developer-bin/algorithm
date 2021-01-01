import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	static long n;
	static long ans;
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		n=scan.nextLong();
		//solve
		long s=1;
		long e=4294967295L;
		while(s<=e) {
			long m=(s+e)/2;
			if(m*(m+1)<=n*2) {
				ans=Math.max(m, ans);
				s=m+1;
			}else {
				e=m-1;
			}
		}
		//print
		System.out.println(ans);
	}
}
