import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
	static int n;
	static int a[]=new int[80001];
	static long ans;
	static Stack<Integer> st=new Stack<Integer>();
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		//input
		n=Integer.parseInt(bf.readLine());
		for(int i=1;i<=n;i++) {
			a[i]=Integer.parseInt(bf.readLine());
		}
		//solve
		for(int i=1;i<=n;i++) {
			int now=a[i];
			if(st.isEmpty()) {
				st.push(now);
			}else if(st.peek()>now) {
				ans+=st.size();
				st.push(now);
			}else if(st.peek()<=now) {
				while(!st.isEmpty()) {
					int top_num=st.peek();
					if(top_num<=now) {
						st.pop();
						continue;
					}else break;
				}
				ans+=st.size();
				st.push(now);
			}
		}
		//print
		System.out.println(ans);
	}
}
