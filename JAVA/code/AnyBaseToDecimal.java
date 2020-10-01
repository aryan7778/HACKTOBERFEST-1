import java.util.*;

public class AnyBase2Decimal 
{

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int b = sc.nextInt();
		int d = getValueInDecimal(n, b);
		System.out.println(d);

	}
	
	public static int getValueInDecimal(int n, int b) 
	{
		int ans = 0;
		int power = 0;
		
		while(n>0)
		{
			int rem = n % 10;
			n /= 10;
			
			ans += rem * Math.pow(b, power);
			power++;
		}
		
		return ans;
	}

}
