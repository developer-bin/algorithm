package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

class node{
	public int order;
	public int priority;
	node(){};
	node(int a,int b){
		this.order=a;
		this.priority=b;
	}
	@Override
	public boolean equals(Object a) {
		node obj=(node) a;
		return (obj.order==this.order && obj.priority==this.priority);
	}
	@Override
	public int hashCode() {
		return Integer.toString(order+priority).hashCode();
	}
}

public class Main {
	static int n;
	static int t;
	static HashSet<node> visit=new HashSet<>();
	static PriorityQueue<node> max_pq=new PriorityQueue<node>(new Comparator<node>() {
		public int compare(node a,node b) {
			if(a.priority>=b.priority)return -1;
			return 1;
		}
	});
	static PriorityQueue<node> min_pq=new PriorityQueue<node>(new Comparator<node>() {
		public int compare(node a,node b) {
			if(a.priority<=b.priority)return -1;
			return 1;
		}
	});
	static void delete(int num) {
		while(true) {
			if(num==1) {
				//최대값 삭제
				if(max_pq.isEmpty()==true) {
					break;
				}
				node node=max_pq.poll();
				if(visit.contains(node)==false) {
					visit.add(node);
					break;
				}
			}else if(num==-1) {
				//최소값 삭제
				if(min_pq.isEmpty()==true) {
					break;
				}
				node node=min_pq.poll();
				if(visit.contains(node)==false) {
					visit.add(node);
					break;
				}
			}	
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		//input
		StringTokenizer st=new StringTokenizer(bf.readLine());
		t=Integer.parseInt(st.nextToken());
		while(t!=0) {
			//init
			visit.clear();
			max_pq.clear();
			min_pq.clear();
			//input and solve
			st=new StringTokenizer(bf.readLine());
			n=Integer.parseInt(st.nextToken());
			for(int i=1;i<=n;i++) {
				st=new StringTokenizer(bf.readLine());
				String op=st.nextToken();
				int num=Integer.parseInt(st.nextToken());
				if(op.equals("I")) {
					max_pq.add(new node(i,num));
					min_pq.add(new node(i,num));
				}else if(op.equals("D")) {
					delete(num);
				}
			}
			//print
			int max_num = 0;
			boolean check=false;
			while(true) {
				if(max_pq.isEmpty()==true) {
					System.out.println("EMPTY");
					check=true;
					break;
				}
				node node=max_pq.poll();
				if(visit.contains(node)==true)continue;
				max_num=node.priority;
				System.out.print(node.priority+" ");
				break;
			}
			if(check==true) {
				t--;
				continue;
			}
			while (true) {
				node node = min_pq.poll();
				if (visit.contains(node) == true)continue;
				System.out.println(node.priority);
				break;
			}
			t--;
		}
	}
}
