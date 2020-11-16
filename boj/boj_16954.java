import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	static char maps[][]=new char[9][9];
	static boolean check;
	static int dx[]= {0,0,-1,1,-1,-1,1,1,0};
	static int dy[]= {1,-1,0,0,-1,1,-1,1,0};
	static boolean visit[][][]=new boolean[9][9][9];
	static boolean boundary(int x,int y) {
		return x>=1 && x<=8 && y>=1 && y<=8;
	}
	static void copy_maps(char from_maps[][],char to_maps[][]) {
		for(int i=1;i<=8;i++) {
			for(int j=1;j<=8;j++) {
				to_maps[i][j]=from_maps[i][j];
			}
		}
	}
	static void under_maps(char u_maps[][]) {
		for(int i=8;i>=2;i--) {
			for(int j=1;j<=8;j++) {
				u_maps[i][j]='.';
				u_maps[i][j]=u_maps[i-1][j];
			}
		}
		for(int j=1;j<=8;j++) {
			u_maps[1][j]='.';
		}
	}
	static void testprint() {
		for(int i=1;i<=8;i++) {
			for(int j=1;j<=8;j++) {
				System.out.print(maps[i][j]);
			}System.out.println();
		}
	}
	static void state(int x,int y,int cnt) {
		//System.out.println(x+", "+y+", "+cnt);
		//testprint();
		//System.out.println();
		if(cnt==8) {
			check=true;
			return;
		}
		if(x==1 && y==8) {
			check=true;
			return;
		}
		char ori_maps[][]=new char[9][9];
		copy_maps(maps,ori_maps);
		for(int i=0;i<9;i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			int n_cnt=cnt+1;
			if(boundary(nx,ny) && visit[nx][ny][n_cnt]==false && maps[nx][ny]=='.') {
				visit[nx][ny][n_cnt]=true;
				under_maps(maps);
				if(maps[nx][ny]=='.') {
					state(nx,ny,n_cnt);
				}
				copy_maps(ori_maps,maps);
			}
		}
	}
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		//input
		for(int i=1;i<=8;i++) {
			String s=bf.readLine();
			for(int j=0;j<s.length();j++) {
				maps[i][j+1]=s.charAt(j);
			}
		}
		//solve
		state(8,1,0);
		//print
		if(check) {
			System.out.println(1);
		}else System.out.println(0);
		return;
	}
}
