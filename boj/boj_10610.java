import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;
class cmp implements Comparator<Integer>{

	@Override
	public int compare(Integer a, Integer b) {
		if(a<b)return 1;
		return -1;
	}
	
}
public class Main {
	static String s;
	static int sum;
	static ArrayList<Integer> v=new ArrayList<Integer>();
	static int cnt[]=new int[10];
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		s=scan.nextLine();
		//solve
		for(int i=0;i<s.length();i++) {
			cnt[s.charAt(i)-'0']+=1;
			sum+=(s.charAt(i)-'0');
		}
		//print
		if(cnt[0]==0 || sum%3!=0) {
			System.out.println(-1);
		}else {
			for(int i=9;i>=0;i--) {
				if(cnt[i]==0)continue;
				for(int j=0;j<cnt[i];j++) {
					System.out.print(i);
				}
			}
		}
	}
}
