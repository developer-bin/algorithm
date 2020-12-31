import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;
import java.util.StringTokenizer;
class node{
	int idx;
	int num;
	node(int idx,int num){
		this.idx=idx;
		this.num=num;
	}
}
class cmp implements Comparator<node>{
	public int compare(node a, node b) {
		if(a.num>=b.num)return -1;
		return 1;
	}
}
public class Main {
	static int a[]=new int[5];
	static ArrayList<node> v=new ArrayList();
	static int sum;
	
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		for(int i=0;i<8;i++) {
			int num=scan.nextInt();
			v.add(new node(i,num));
		}
		//solve
		Collections.sort(v,new cmp());
		for(int i=0;i<5;i++) {
			sum+=v.get(i).num;
			a[i]=v.get(i).idx+1;
		}
		Arrays.sort(a);
		//print
		System.out.println(sum);
		for(int i=0;i<5;i++) {
			System.out.print(a[i]+" ");
		}
	}
}
