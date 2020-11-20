import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;
class node{
	node(int a,int b,int c){
		this.a=a;
		this.b=b;
		this.c=c;
	}
	int a;int b;int c;

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + a;
		result = prime * result + b;
		result = prime * result + c;
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		node other = (node) obj;
		if (a != other.a)
			return false;
		if (b != other.b)
			return false;
		if (c != other.c)
			return false;
		return true;
	}
	
}
public class Main {
	static boolean visit[][][]=new boolean[1501][1501][1501];
	static boolean check;
	static HashMap<node,Boolean> maps=new HashMap<node,Boolean>();
	static void state(int a,int b,int c) {
		maps.put(new node(a,b,c), true);
		if(a==b && a==c && b==c) {
			check=true;
			return;
		}
		if(a<b) {
			if(b-a>=0 && maps.containsKey(new node(a+a,b-a,c))==false) {
				state(a+a,b-a,c);
			}
		}
		if(a>b) {
			if(a-b>=0 && maps.containsKey(new node(a-b,b+b,c))==false) {
				state(a-b,b+b,c);
			}
		}
		if(a<c) {
			if(c-a>=0 && maps.containsKey(new node(a+a,b,c-a))==false) {
				state(a+a,b,c-a);
			}
		}
		if(a>c) {
			if(a-c>=0 && maps.containsKey(new node(a-c,b,c+c))==false) {
				state(a-c,b,c+c);
			}
		}
		if(b<c) {
			if(c-b>=0 && maps.containsKey(new node(a,b+b,c-b))==false) {
				state(a,b+b,c-b);
			}
		}
		if(b>c) {
			if(b-c>=0 && maps.containsKey(new node(a,b-c,c+c))==false) {
				state(a,b-c,c+c);
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st=new StringTokenizer(bf.readLine());
		int a=Integer.parseInt(st.nextToken());
		int b=Integer.parseInt(st.nextToken());
		int c=Integer.parseInt(st.nextToken());
		//solve
		state(a,b,c);
		//print
		if(check)System.out.println(1);
		else System.out.println(0);
	}
}