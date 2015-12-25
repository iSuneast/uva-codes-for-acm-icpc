/*
787 - Maximum Sub-sequence Product
 * Java赞一个先...
 * 虽然说是DP题...
 * 竟然加了高精度...
 * 好无语的说....
 * 暴力O(n^3)直接过了...
*/

//package main;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        BigInteger a,t,key;
        BigInteger[] dp=new BigInteger[110];
        while(in.hasNext())
        {
            int p=0;
            do
            {
                dp[p]=in.nextBigInteger();
                if(dp[p].compareTo(BigInteger.valueOf(-999999))==0)
                    break;
                ++p;
            }while(true);
            key=dp[0];
            for(int start=0;start<p;++start)
                for(int end=start;end<p;++end)
                {
                    t=dp[start];
                    for(int k=start+1;k<=end;++k)
                        t=t.multiply(dp[k]);
                    if(t.compareTo(key)>0)
                        key=t;
                }
            System.out.println(key);
        }
    }
}
