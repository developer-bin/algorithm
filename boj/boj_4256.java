import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static int t,n;
	static int in_pos[]=new int[1001];
	static void post_order(int pre_s,int pre_e,int in_s,int in_e,ArrayList<Integer> pre_v,ArrayList<Integer> in_v) {
		if(pre_s>pre_e || in_s>in_e)return;
		int pre_root_num=pre_v.get(pre_s);
		int in_root_idx=in_pos[pre_root_num];
		int in_left_cnt=in_root_idx-in_s;
		int in_right_cnt=in_e-in_root_idx;
		post_order(pre_s+1,pre_s+in_left_cnt,in_s,in_root_idx-1,pre_v,in_v);
		post_order(pre_e-in_right_cnt+1,pre_e,in_root_idx+1,in_e,pre_v,in_v);
		System.out.print(pre_root_num+" ");
	}
	public static void main(String[] args) throws IOException{
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		t=Integer.parseInt(bf.readLine());
		while(t--!=0) {
			n=Integer.parseInt(bf.readLine());
			ArrayList<Integer> pre_v=new ArrayList<Integer>();
			ArrayList<Integer> in_v=new ArrayList<Integer>();
			st=new StringTokenizer(bf.readLine());
			while(st.hasMoreTokens()) {
				pre_v.add(Integer.parseInt(st.nextToken()));
			}
			st=new StringTokenizer(bf.readLine());
			while(st.hasMoreTokens()) {
				int num=Integer.parseInt(st.nextToken());
				in_pos[num]=in_v.size();
				in_v.add(num);
			}
			post_order(0,n-1,0,n-1,pre_v,in_v);
			System.out.println();
		}
		//solve
		//print
	}

}
