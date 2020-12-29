import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n,k;
	static int a[]=new int[5000000];
	static void merge(int s1,int e1,int s2,int e2) {
		int idx1=s1;
		int idx2=s2;
		int n_idx=0;
		int mid_a[]=new int[e2-s1+1];
		while(idx1<=e1 && idx2<=e2) {
			if(a[idx1]<a[idx2]) {
				mid_a[n_idx++]=a[idx1];
				idx1+=1;
			}else if(a[idx1]>a[idx2]) {
				mid_a[n_idx++]=a[idx2];
				idx2+=1;
			}else if(a[idx1]==a[idx2]) {
				mid_a[n_idx++]=a[idx1];
				mid_a[n_idx++]=a[idx2];
				idx1+=1;
				idx2+=1;
			}
		}
		while(idx1<=e1) {
			mid_a[n_idx++]=a[idx1++];
		}
		while(idx2<=e2) {
			mid_a[n_idx++]=a[idx2++];
		}
		n_idx=0;
		for(int i=s1;i<=e2;i++) {
			a[i]=mid_a[n_idx++];
		}
	}
	static void go(int s,int e) {
		if(s<e) {
			int mid=(s+e)/2;
			go(s,mid);
			go(mid+1,e);
			merge(s,mid,mid+1,e);
		}
	}
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		k=Integer.parseInt(st.nextToken());
		st=new StringTokenizer(bf.readLine());
		for(int i=0;i<n;i++) {
			a[i]=Integer.parseInt(st.nextToken());
		}
		//solve
		go(0,n-1);
		//print
		System.out.println(a[k-1]);
	}
}
