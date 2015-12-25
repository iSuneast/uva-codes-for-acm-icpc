/*
 * 11161 - Help My Brother (II)
 * 
 * Bign...
 * math...
 * java再次发挥bign的强大力量
 */

package Main;
import java.util.*;
import java.math.*;

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        int maxn=1501;
        BigInteger fib[]=new BigInteger[maxn];
        BigInteger sum[]=new BigInteger[maxn];
        sum[0]=BigInteger.ZERO;
        sum[1]=fib[1]=BigInteger.ONE;
        fib[2]=BigInteger.valueOf(2);
        sum[2]=BigInteger.valueOf(3);

        for(int i=3;i<maxn;++i)
        {
            fib[i]=fib[i-1].add(fib[i-2]);
            sum[i]=sum[i-1].add(fib[i]);
        }

        int cas=1;
        while(in.hasNext())
        {
            int n=in.nextInt()-1;
            if(n==-1)
                break;
            System.out.printf("Set %d:",cas++);
            System.out.println();
            if(n==0)
            {
                System.out.println(0);
                continue;
            }
            BigInteger ans=sum[n-1].add(BigInteger.ONE);
            System.out.println(ans.add(sum[n]).divide(BigInteger.valueOf(2)));
        }
    }

}
