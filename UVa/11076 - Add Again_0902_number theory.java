/*
 * 11076 - Add Again
 * 
 * number theory...
 * for example 
 * n=3 112 we'll got 
 *   ( 1?? + ?1? +??1 ) * 2
 * + ( 2?? + ?2? +??2 ) * 1
 * = 111*2 + 222*1
 * 
 * n=3 123
 *   ( 1?? + ?1? +??1 ) * 2
 * + ( 2?? + ?2? +??2 ) * 2
 * + ( 3?? + ?3? +??3 ) * 2
 * = 111*2 + 222*2 + 333*2
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static BigInteger c(int n,int m)
    {
        BigInteger key=BigInteger.ONE;
        for(int i=1;i<=n;++i)
            key=key.multiply(BigInteger.valueOf(i));
        for(int i=1;i<=m;++i)
            key=key.divide(BigInteger.valueOf(i));
        m=n-m;
        for(int i=1;i<=m;++i)
            key=key.divide(BigInteger.valueOf(i));
        return key;
    }
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int flag[]=new int[15];
        while(in.hasNext())
        {
            int n=in.nextInt();
            if(n==0)
                break;
            BigInteger ans=BigInteger.ZERO;
            for(int i=0;i<10;++i)
            {
                flag[i]=0;
            }
            for(int i=0;i<n;++i)
            {
                ++flag[ in.nextInt() ];
            }

            for(int i=1;i<10;++i)
            {
                if(flag[i]>0)
                {
                    BigInteger t=BigInteger.ZERO,more=BigInteger.ONE;
                    for(int j=0;j<n;++j)
                    {
                        t=t.multiply(BigInteger.valueOf(10)).add(BigInteger.valueOf(i));
                    }

                    int rem=n-1;
                    for(int j=0;j<10;++j)
                    {
                        if(j==i || flag[j]==0)
                            continue;
                        more=more.multiply(c(rem,flag[j]));
                        rem-=flag[j];
                    }
                    ans=ans.add( t.multiply(more) );
                }
            }

            System.out.println(ans);
        }
    }

}
