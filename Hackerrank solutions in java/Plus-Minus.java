import java.util.Scanner;

public class PlusMinus 
{
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		double plus=0,minus=0,zero=0;
		int arr[]=new int[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=sc.nextInt();
			if(arr[i]>0)
			{
				plus++;
			}
			if(arr[i]<0)
			{
				minus++;
			}
			if(arr[i]==0)
			{
				zero++;
			}
		}
		sc.close();
		System.out.printf("%.6f \n", plus/n);
		System.out.printf("%.6f \n", minus/n);
		System.out.printf("%.6f \n", zero/n);
	}

}
