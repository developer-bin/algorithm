import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	static int e,s,m;
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		st=new StringTokenizer(bf.readLine());
		e=Integer.parseInt(st.nextToken());
		s=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		//solve
		int ee=1,ss=1,mm=1,day=1;
		while(true) {
			if(ee==e && ss==s && mm==m) {
				break;
			}
			ee+=1;ss+=1;mm+=1;day+=1;
			if(ee==16)ee=1;
			if(ss==29)ss=1;
			if(mm==20)mm=1;
		}
		//print
		System.out.println(day);
	}
}
