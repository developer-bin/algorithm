import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	final static int MAX_VALUE=2000000000;
	final static int MIN_VALUE=-2000000000;
	static ArrayList<Integer> v=new ArrayList<Integer>();
	static int n;
	static int d[]=new int[10001];
	static int state(int idx) {
		if(idx==n)return 0;
		if(d[idx]!=-1)return d[idx];
		int max_value=MIN_VALUE;
		int min_value=MAX_VALUE;
		d[idx]=MIN_VALUE;
		for(int i=idx;i<n;i++) {
			max_value=Math.max(max_value, v.get(i));
			min_value=Math.min(min_value, v.get(i));
			d[idx]=Math.max(d[idx], max_value-min_value+state(i+1));
		}
		return d[idx];
	}
	public static void main(String[] args) throws IOException{
		//init
		Arrays.fill(d, -1);
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		n=Integer.parseInt(bf.readLine());
		st=new StringTokenizer(bf.readLine());
		while(st.hasMoreTokens()) {
			v.add(Integer.parseInt(st.nextToken()));
		}
		//solve
		System.out.println(state(0));
		//print
	}

}
