import java.util.*;

public class Decimal2AnyBase 
{

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int b = sc.nextInt();
		int dn = getValueInBase(n, b);
		System.out.println(dn);
	}
	
	public static int getValueInBase(int n, int b) 
	{
		int place = 1;
		int ans = 0;
		while(n>0)
		{
			int rem = n % b;
			n /= b;
			
			ans += rem * place;
			place *= 10;
		}
		
		return ans;
	}

}
