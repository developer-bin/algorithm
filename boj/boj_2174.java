import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;
class node{
	int x; int y; int dist;
	node(int x,int y,int dist){
		this.x=x;
		this.y=y;
		this.dist=dist;
	}
}
class cmp implements Comparator<node>{
	@Override
	public int compare(node a,node b) {
		if(a.x<b.x) {
			if(a.y>b.y) {
				return -1;
			}
		}
		return 1;
	}
}
public class Main {
	static boolean visit[][]=new boolean[101][101];
	static int num_arr[][]=new int[101][101];
	static int a,b,n,m;
	static ArrayList<node> input_arr=new ArrayList<>();
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	static boolean boundary(int x,int y) {
		return x>=1 && x<=b && y>=1 && y<=a;
	}
	static int weight_dist(String dist) {
		if(dist.compareTo("L")==0)return 1;
		else return -1;
	}
	static int convert_dist(int dist,String op) {
		if(op.compareTo("L")==0) {
			dist-=1;
			if(dist==-1)dist=3;
		}else if(op.compareTo("R")==0) {
			dist+=1;
			if(dist==4)dist=0;
		}
		return dist;
	}
	static int dist_str_to_int(String dist) {
		if(dist.compareTo("N")==0) {
			return 0;
		}else if(dist.compareTo("E")==0) {
			return 1;
		}else if(dist.compareTo("S")==0) {
			return 2;
		}else {
			return 3;
		}
	}
	static int move_dist_convert(int dist) {
		if(dist==0)return 2;
		else if(dist==2)return 0;
		else if(dist==3)return 3;
		else return 1;
	}
	static boolean go(int robot_num,String op,int loop_num) {
		if(op.compareTo("L")==0 || op.compareTo("R")==0) {
			node node=input_arr.get(robot_num-1);
			int x=node.x;
			int y=node.y;
			int dist=node.dist;
			while(loop_num!=0) {
				dist=convert_dist(dist,op);
				loop_num--;
			}
			input_arr.set(robot_num-1, new node(x,y,dist));	
		}else if(op.compareTo("F")==0) {
			node node=input_arr.get(robot_num-1);
			int x=node.x;
			int y=node.y;
			int dist=node.dist;
			int move_dist=move_dist_convert(dist);
			while(loop_num!=0) {
				int nx=x+dx[move_dist];
				int ny=y+dy[move_dist];
				if(boundary(nx,ny)==false) {
					System.out.println("Robot "+robot_num+" crashes into the wall");
					return false;
				}
				if(visit[nx][ny]==true) {
					System.out.println("Robot "+robot_num+" crashes into robot "+num_arr[nx][ny]);
					return false;
				}
				visit[x][y]=false;
				num_arr[x][y]=0;
				x=nx;
				y=ny;
				visit[x][y]=true;
				num_arr[x][y]=robot_num;
				loop_num--;
			}
			input_arr.set(robot_num-1,new node(x,y,dist));
		}
		return true;
	}
	public static void main(String[] args) throws IOException{
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer input=new StringTokenizer(bf.readLine());
		//input
		a=Integer.parseInt(input.nextToken());
		b=Integer.parseInt(input.nextToken());
		input=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(input.nextToken());
		m=Integer.parseInt(input.nextToken());
		for(int i=1;i<=n;i++) {
			input=new StringTokenizer(bf.readLine());
			int y=Integer.parseInt(input.nextToken());
			int x=Integer.parseInt(input.nextToken());
			String dist=input.nextToken();
			input_arr.add(new node(x,y,dist_str_to_int(dist)));
			if(visit[x][y]==false) {
				visit[x][y]=true;
				num_arr[x][y]=i;
			}else {
				System.out.println("Robot "+i+" crashes into robot "+num_arr[x][y]);
				return;
			}
			if(boundary(x,y)==false) {
				System.out.println("Robot "+i+" crashes into the wall");
				return;
			}
		}
		//solve
		for(int i=1;i<=m;i++) {
			input=new StringTokenizer(bf.readLine());
			int robot_num=Integer.parseInt(input.nextToken());
			String op=input.nextToken();
			int loop_num=Integer.parseInt(input.nextToken());
			if(go(robot_num,op,loop_num)==false) {
				return;
			}
		}
		System.out.println("OK");
	}
}
