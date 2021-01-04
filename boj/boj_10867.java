import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;
import java.util.StringTokenizer;
public class Main {
	static int n;
	static HashSet<Integer> sets=new HashSet<Integer>();
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		Scanner scan=new Scanner(System.in);
		//input
		n=scan.nextInt();
		for(int i=1;i<=n;i++) {
			int num=scan.nextInt();
			sets.add(num);
		}
		//solve
		ArrayList<Integer> v=new ArrayList(sets);
		Collections.sort(v);
		//print
		for(int i=0;i<v.size();i++) {
			System.out.print(v.get(i)+" ");
		}
	}
}
