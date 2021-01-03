import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int n,k;
	static int a[]=new int[5000000];
	static void swap(int idx1,int idx2) {
		int tmp=a[idx1];
		a[idx1]=a[idx2];
		a[idx2]=tmp;
	}
	static void quick_sort(int s,int e) {
		if(s>=e)return;
		int pivot=a[s];
		int idx1=s+1;
		int idx2=e;
		while(idx1<=idx2) {
			while(idx1<=e && a[idx1]<pivot) {idx1+=1;}
			while(idx2>=s+1 && a[idx2]>pivot) {idx2-=1;}
			if(idx1>idx2) {
				swap(s,idx2);
			}else {
				swap(idx1,idx2);
			}
		}
		quick_sort(s,idx2-1);
		quick_sort(idx2+1,e);
	}
	public static void main(String[] args) throws IOException{ 
		//init
		BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		//input
		st=new StringTokenizer(bf.readLine());
		n=Integer.parseInt(st.nextToken());
		for(int i=0;i<n;i++) {
			st=new StringTokenizer(bf.readLine());
			a[i]=Integer.parseInt(st.nextToken());
		}
		//solve
		quick_sort(0,n-1);
		//print
		for(int i=0;i<n;i++) {
			System.out.println(a[i]);
		}
	}
}
