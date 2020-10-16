package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int dist[][]=new int[401][401];
	static int v,e;
	final static int MAX_VALUE=200000000;
	final static int MIN_VALUE=-200000000;
	static int ans=MAX_VALUE;
	public static void main(String[] args) throws IOException{
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer input;
		for(int i=1;i<=400;i++) {
			for(int j=1;j<=400;j++) {
				dist[i][j]=MAX_VALUE;
			}
		}
		input=new StringTokenizer(bf.readLine());
		v=Integer.parseInt(input.nextToken());
		e=Integer.parseInt(input.nextToken());
		for(int i=1;i<=e;i++) {
			input=new StringTokenizer(bf.readLine());
			int from,to,cost;
			from=Integer.parseInt(input.nextToken());
			to=Integer.parseInt(input.nextToken());
			cost=Integer.parseInt(input.nextToken());
			dist[from][to]=cost;
		}
		//solve
		for(int k=1;k<=v;k++) {
			for(int i=1;i<=v;i++) {
				for(int j=1;j<=v;j++) {
					dist[i][j]=Math.min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
		for(int i=1;i<=v;i++) {
			ans=Math.min(ans,dist[i][i]);
		}
		//print
		if(ans==MAX_VALUE)ans=-1;
		System.out.println(ans);
	}
}
