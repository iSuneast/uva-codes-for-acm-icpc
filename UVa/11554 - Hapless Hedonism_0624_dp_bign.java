/*
 * 11554 - Hapless Hedonism
 * 
 * dp...
 * bign...
 * 汗...
 * 这题时限只有2s...
 * java用了1.8s...卡过...
 * *****************************
 * 3        0
 * 4        1
 * 5        3
 * 6        7
 * ......
 * n        dp(n-1)+(n-3)+(n-5)+...
 * ******************************
 * 很明显的递推关系
 * 注意一下后面的求和必须用求和公式...
 * 不能直接用for暴力算...
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int MAXN=1000001;
        BigInteger dp[]=new BigInteger[MAXN];
        dp[3]=BigInteger.ZERO;
        for(int i=4;i<MAXN;++i)
        {
            long s=i-3;
            if(s%2==1)
            {
                s=(s+1)/2;
                dp[i]=dp[i-1].add(BigInteger.valueOf(s*s));
            }
            else
            {
                s/=2;
                dp[i]=dp[i-1].add(BigInteger.valueOf(s*s+s));
            }
        }
        int dataset=in.nextInt();
        while(dataset-->0)
            System.out.println(dp[in.nextInt()]);
    }

}
