import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

class pair{
	int first;
	int second;
	pair(int x,int y){
		this.first=x;
		this.second=y;
	}
}
public class Main {
	static int t;
	static int k;
	static ArrayList<pair> v=new ArrayList<>();
	static int d[][]=new int[101][10001];
	static int state(int idx,int sum) {
		if(idx==v.size()) {
			if(sum==t)return 1;
			else return 0;
		}
		if(sum==t)return 1;
		if(sum>t)return 0;
		if(d[idx][sum]!=-1)return d[idx][sum];
		int result=0;
		for(int cnt=0;cnt<=v.get(idx).second;cnt++) {
			result+=state(idx+1,sum+v.get(idx).first*cnt);
		}
		return d[idx][sum]=result;
	}
	public static void main(String[] args) throws IOException {
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer input;
		for(int i=0;i<=100;i++) {
			for(int j=0;j<=10000;j++) {
				d[i][j]=-1;
			}
		}
		//input
		input=new StringTokenizer(bf.readLine());
		t=Integer.parseInt(input.nextToken());
		input=new StringTokenizer(bf.readLine());
		k=Integer.parseInt(input.nextToken());
		for(int i=1;i<=k;i++) {
			input=new StringTokenizer(bf.readLine());
			int first,second;
			first=Integer.parseInt(input.nextToken());
			second=Integer.parseInt(input.nextToken());
			v.add(new pair(first,second));
		}
		//solve
		System.out.println(state(0,0));
	}
}
