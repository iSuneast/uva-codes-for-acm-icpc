/*
 * 10523 - Very Easy !!!
 * 
 * 不愧是java...
 * 高精度问题一下子搞定...
 */

//package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int maxn=151,maxa=16;
        BigInteger ans[][]=new BigInteger[maxn][maxa];

        int tot=0;
        for(int i=1;i<maxn;++i)
        {
            tot+=i;
            ans[i][0]=BigInteger.ZERO;
            ans[i][1]=BigInteger.valueOf(tot);
        }

        for(int a=2;a<maxa;++a)
        {
            ans[0][a]=BigInteger.ZERO;
            BigInteger t=BigInteger.ONE;
            for(int n=1;n<maxn;++n)
            {
                t=t.multiply(BigInteger.valueOf(a));
                ans[n][a]=ans[n-1][a].add(t.multiply(BigInteger.valueOf(n)));
            }
        }

        while(in.hasNext())
        {
            int n=in.nextInt();
            int a=in.nextInt();
            System.out.println(ans[n][a]);
        }
    }

}
