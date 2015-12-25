/*
 * 11375 - Matches
 * 又是带高精度dp题
 * 开始喜欢上java的Bignum了...
 */
//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int MAXN=2001;
        BigInteger dp[][]=new BigInteger[2][MAXN];
        BigInteger ans[]=new BigInteger[MAXN];
        int match[]={6,2,5,5,4,5,6,3,7,6};      //火柴要用到的棒子个数
        for(int i=0;i<MAXN;++i)
            ans[i]=dp[0][i]=dp[1][i]=BigInteger.ZERO;
        dp[0][0]=BigInteger.ONE;
        for(int i=0;i<MAXN;++i)         //背包
        {
            if(i>=match[0])             //可以以0开头
                dp[0][i]=dp[0][i].add(dp[0][i-match[0]].add(dp[1][i-match[0]]));
            for(int j=1;j<10;++j)       //非0开头的解的个数
                if(i>=match[j])
                    dp[1][i]=dp[1][i].add(dp[0][i-match[j]].add(dp[1][i-match[j]]));
            if(i>=1)
                ans[i]=dp[1][i].add(ans[i-1]);
            if(i==match[0])     //当i=6时解的个数可以为0，要加一
                ans[i]=ans[i].add(BigInteger.ONE);
        }
        while(in.hasNext())
        {
            int n=in.nextInt();
            System.out.println(ans[n]);
        }
    }

}
