/*
 * 10081 - Tight Words
 * 
 * dp...
 * 水题一个,但是要高精度...
 * 所以就用java了~
 * dp[k][n] = dp[k+1][n-1] + dp[k][n-1] + dp[k-1][n-1]
 * 当k==0 || k==K时特判即可~
 * 
 * happy coding~
 */

import java.util.*;
import java.math.*;

public class Main {
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		BigInteger dp[][]=new BigInteger [10][101];
		int k,n;
		while(in.hasNext())
		{
			k=in.nextInt();
			n=in.nextInt();
			BigInteger tot=BigInteger.ONE;
			for(int i=1;i<=n;++i)
			{
				tot=tot.multiply( BigInteger.valueOf(k+1) );
			}
			
			for(int l=1;l<=n;++l)
			{
				for(int i=0;i<=k;++i)
					dp[i][l]=(l==1)?BigInteger.ONE:BigInteger.ZERO;
			}
			
			for(int l=2;l<=n;++l)
			{
				for(int i=0;i<=k;++i)
				{
					if(i>0)		dp[i][l]=dp[i][l].add( dp[i-1][l-1] );
					if(i<k)		dp[i][l]=dp[i][l].add( dp[i+1][l-1] );
					dp[i][l]=dp[i][l].add( dp[i][l-1] );
				}
			}
			
			BigInteger sum=BigInteger.ZERO;
			for(int i=0;i<=k;++i)
			{
				sum=sum.add( dp[i][n] );
			}
			
			sum=sum.multiply( BigInteger.valueOf(100000000) );
			
			int key=(int)sum.divide(tot).longValue(), add=0;
			if(key%10>4)
				add=1;
			key=key/10+add;
			
			int t=key%100000;
			String tail=String.valueOf(t);
			if(t==0)
				add=1;
			else
				add=0;
			while(t>0)
			{
				t/=10;
				++add;
			}
			for(;add<5;++add)
			{
				tail="0"+tail;
			}
			
			System.out.println(key/100000+"."+tail);
		}
		
	}
}
