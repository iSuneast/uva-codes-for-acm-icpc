/*
 * 10359 - Tiling
 *
 * dp...
 * a simple dp problem
 * dp[n]=dp[n-1]+dp[n-2]*2
 * with dp[0]=dp[1]=1
 *
 * happy coding...
 */

import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        final int MAXN=251;
        BigInteger dp[]=new BigInteger [MAXN];

        dp[0]=BigInteger.ONE;
        dp[1]=BigInteger.ONE;
        for(int i=2;i<MAXN;++i)
        {
            dp[i]=dp[i-2].add( dp[i-1] ).add( dp[i-2] );
        }

        while(in.hasNext())
            System.out.println(dp[ in.nextInt() ]);
    }

}
