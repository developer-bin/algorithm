import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
	final static int MAX_VALUE=2000000000;
	static int n,m;
	static int ans=MAX_VALUE;
	static ArrayList<Integer> v=new ArrayList<Integer>();
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st=new StringTokenizer(bf.readLine());
		//input
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		while(n--!=0) {
			v.add(Integer.parseInt(bf.readLine()));
		}
		//solve
		Collections.sort(v);
		int l=0,r=0;
		while(true) {
			if(l==v.size()-1 && r==v.size()-1)break;
			int a=v.get(l);
			int b=v.get(r);
			if(r==v.size()-1) {
				if(b-a>=m) {
					ans=Math.min(ans, b-a);
				}
				l+=1;
			}else if(a==b)r+=1;
			else if(b-a<m)r+=1;
			else if(b-a==m) {
				ans=Math.min(ans, b-a);
				r+=1;
			}else if(b-a>m) {
				ans=Math.min(ans, b-a);
				l+=1;
			}
		}
		//print
		System.out.println(ans);
	}
}
