import java.util.Scanner;

public class Main {
	static int month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
	static String[] ans = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
	static int sum;
	public static void main(String[] args) {
		//init
		//input
		Scanner scan=new Scanner(System.in);
		int m=scan.nextInt();
		int d=scan.nextInt();
		//solve
		for(int i=1;i<=m-1;i++) {
			sum+=month[i];
		}
		sum+=d-1;
		sum%=7;
		System.out.println(ans[sum]);
	}

}
