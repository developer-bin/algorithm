import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static ArrayList<Integer> v=new ArrayList<Integer>();
	static int w;
	static int h;
	static int ans;
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		h=Integer.parseInt(st.nextToken());
		w=Integer.parseInt(st.nextToken());
		st=new StringTokenizer(bf.readLine());
		while(st.hasMoreTokens()) {
			v.add(Integer.parseInt(st.nextToken()));
		}
		//solve
		for(int i=1;i<v.size()-1;i++) {
			int now_idx=i;
			boolean check=false;
			int left_max=v.get(now_idx);
			int right_max=v.get(now_idx);
			for(int j=now_idx-1;j>=0;j--) {
				left_max=Math.max(left_max, v.get(j));
			}
			for(int j=i+1;j<v.size();j++) {
				right_max=Math.max(right_max, v.get(j));
			}
			if(left_max==v.get(now_idx) || right_max==v.get(now_idx))continue;
			ans+=Math.min(left_max-v.get(now_idx), right_max-v.get(now_idx));
		}
		//print
		System.out.println(ans);
		return;
	}

}
