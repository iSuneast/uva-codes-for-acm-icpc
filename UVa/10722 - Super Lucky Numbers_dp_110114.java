/*
 * 10722 - Super Lucky Numbers
 * 
 * dp...
 * a fairy straight DP problem...
 * but I just try to make it complex..
 * poor ;(
 * 
 * we can use an array dp[3][N] to store the total number of numbers length=N
 * dp[0][1]=1	//stand for '1' in N=1
 * dp[1][1]=1	//stand for '3' in N=1
 * dp[2][1]=B-3	//stand for all the others except for '0','1','3'
 * 
 * dp[0][i]=dp[0][i-1] + dp[1][i-1] + dp[2][i-1]
 * dp[1][i]=dp[1][i-1] + dp[2][i-1]
 * dp[2][i]=( dp[0][i-1] + dp[1][i-1] + dp[2][i-1] )* (B-2);
 * 
 * then the desire answer is dp[0][N] + dp[1][N] + dp[2][N]
 * just keep it simple...
 * 
 * happy coding..
 */

import java.math.*;
import java.util.*;

public class Main {
	static final int MAXN=101;
	static BigInteger dp[][]=new BigInteger[3][MAXN];
		
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);

		while(in.hasNext())
		{
			int B=in.nextInt(), N=in.nextInt();
			if(B==0 && N==0)
				break;
			
			dp[0][1]=dp[1][1]=BigInteger.ONE;
			dp[2][1]=BigInteger.valueOf(B-3);
			for(int i=2;i<=N;++i)
			{
				dp[0][i]=dp[0][i-1].add( dp[1][i-1] ).add( dp[2][i-1] );
				dp[1][i]=dp[1][i-1].add( dp[2][i-1] );
				dp[2][i]=dp[0][i-1].add( dp[1][i-1] ).add( dp[2][i-1] ).multiply( BigInteger.valueOf(B-2) );
			}

			System.out.println(dp[0][N].add( dp[1][N] ).add( dp[2][N] ));
		}
	}
}

